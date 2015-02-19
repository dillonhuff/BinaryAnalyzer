#include "arm/arm_disassembler.h"
#include "arm/class_32_decoder.h"
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

arm_instruction* arm_disassembler::decode_arm6m_32(word16* w1, word16* w2) {
  auto instr = new arm_instruction(w1, w2);
  auto top = w1->get_bits(15, 0);
  auto bottom = w2->get_bits(15, 0);
  top.insert(top.end(), bottom.begin(), bottom.end());
  auto instr_bits = new bit_field(top);
  std::cout << "instruction bits" << std::endl;
  std::cout << instr_bits->to_string() << std::endl;
  class_32_decoder.decode(instr, instr_bits);
  return instr;
}

arm_instruction* arm_disassembler::decode_arm6m_16(word16* w) {
  auto instr = new arm_instruction(w);
  return instr;
}

std::unique_ptr<arm_instruction_sequence> arm_disassembler::disassembleARM6M(unsigned int start_addr, endianness end, const unsigned char* bytes, unsigned int n) {
  std::cout << "DEBUG: n = " << std::to_string(n) << std::endl;
  auto word16_list = convert_to_word16(end, bytes, n);
  auto instrs = new arm_instruction_sequence(start_addr);
  unsigned int i = 0;
  while (i < word16_list.size()) {
    if (is_start_of_32_bit_instruction(*(word16_list[i]))) {
      std::cout << "32 bit instruction" << std::endl;
      auto instr = decode_arm6m_32(word16_list[i].get(), word16_list[i+1].get());
      instrs->add_instruction(instr);
      i += 2;
    } else {
      std::cout << "16 bit instruction" << std::endl;
      auto instr = decode_arm6m_16(word16_list[i].get());
      instrs->add_instruction(instr);
      i += 1;
    }
  }
  return std::unique_ptr<arm_instruction_sequence>(instrs);
}
