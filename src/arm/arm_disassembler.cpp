#include "arm_disassembler.h"
#include "utils/bit.h"
#include "utils/bit_pattern_table.hpp"
#include "utils/word16.h"

#include <iostream>
#include <string>

bit_p p32_1[5] = {one, one, one, zero, one};
bit_p p32_2[5] = {one, one, one, one, zero};
bit_p p32_3[5] = {one, one, one, one, one};

bit_pattern pat32_1 = bit_pattern(p32_1, 5);
bit_pattern pat32_2 = bit_pattern(p32_2, 5);
bit_pattern pat32_3 = bit_pattern(p32_3, 5);

bool arm_disassembler::is_start_of_32_bit_instruction(word16& w) {
  auto w_b = w.get_bits(15, 11);
  return pat32_1.matches(w_b) || pat32_2.matches(w_b) || pat32_3.matches(w_b);
}

bit_p undef_32_1[14] = {any, one,
			any, any, any, any, any, any, any, any, any, any, any,
			any};
bit_p undef_32_2[14] = {one, zero,
			any, any, any, any, any, any, any, any, any, any, any,
			zero};
bit_p branch_and_misc_control[14] = {one, zero,
				     any, any, any, any, any, any, any, any, any, any, any,
				     one};

bit_p* instr_class_32[3] = {undef_32_1, undef_32_2, branch_and_misc_control};

std::string instr_class_32_names[3] = {"UNDEFINED", "UNDEFINED", "BRANCH_AND_MISC_CONTROL"};

auto class_32_table =
  bit_pattern_table<std::string>(instr_class_32, instr_class_32_names, 3, 14);

arm_instruction* arm_disassembler::decode_arm6m_16(word16* w) {
  auto instr = new arm_instruction(w);
  return instr;
}

void arm_disassembler::decode_arm6m_class_32(arm_instruction* instr, word16* w1, word16* w2) {
  auto w1_bits = w1->get_bits(12, 0);
  auto w2_bits = w2->get_bits(15, 15);
  w1_bits.insert(w1_bits.end(), w2_bits.begin(), w2_bits.end());
  instr->set_class(class_32_table.match(w1_bits));
}

arm_instruction* arm_disassembler::decode_arm6m_32(word16* w1, word16* w2) {
  auto instr = new arm_instruction(w1, w2);
  decode_arm6m_class_32(instr, w1, w2);
  return instr;
}


std::unique_ptr<arm_instruction_sequence> arm_disassembler::disassembleARM6M(unsigned int start_addr, endianness end, const char* bytes, unsigned int n) {
  std::cout << "DEBUG: n = " << std::to_string(n) << std::endl;
  auto word16_list = convert_to_word16(end, bytes, n);
  auto instrs = new arm_instruction_sequence(start_addr);
  unsigned int i = 0;
  while (i < word16_list.size()) {
    if (is_start_of_32_bit_instruction(*(word16_list[i]))) {
      auto instr = decode_arm6m_32(word16_list[i].get(), word16_list[i+1].get());
      instrs->add_instruction(instr);
      i += 2;
    } else {
      auto instr = decode_arm6m_16(word16_list[i].get());
      instrs->add_instruction(instr);
      i += 1;
    }
  }
  return std::unique_ptr<arm_instruction_sequence>(instrs);
}
