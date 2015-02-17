#include "arm_disassembler.h"
#include "utils/bit.h"
#include "utils/word16.h"

#include <iostream>

bit p1[5] = {ONE, ONE, ONE, ZERO, ONE};
bit p2[5] = {ONE, ONE, ONE, ONE, ZERO};
bit p3[5] = {ONE, ONE, ONE, ONE, ONE};

std::vector<bit> vp1(p1, p1 + sizeof p1 / sizeof p1[0]);
std::vector<bit> vp2(p2, p2 + sizeof p2 / sizeof p2[0]);
std::vector<bit> vp3(p3, p3 + sizeof p3 / sizeof p3[0]);

// 16 bit Thumb instruction classes
bit shift16_class[2] = {ZERO, ZERO};
bit special16_class[6] = {ZERO, ONE, ZERO, ZERO, ZERO, ONE};

std::vector<bit> shift16_class_v(shift16_class, shift16_class + sizeof shift16_class / sizeof shift16_class[0]);
std::vector<bit> special16_class_v(special16_class, special16_class + sizeof special16_class / sizeof special16_class[0]);

// ---------------------------------------------

// Shift (immediate), add, subtract, move and compare bit vectors
bit add16[5] = {ZERO, ONE, ONE, ZERO, ZERO};

std::vector<bit> add16_v(add16, add16 + sizeof add16 / sizeof add16[0]);
// ----------------------------------------------------------

// Special data instructions
bit special_add16[2] = {ZERO, ZERO};

std::vector<bit> special_add16_v(special_add16, special_add16 + sizeof special_add16 / sizeof special_add16[0]);
// ----------------------------------------------------------

bool arm_disassembler::is_16_bit_shift_class(word16* w) {
  return w->get_bits(15, 14) == shift16_class_v;
}

bool arm_disassembler::is_16_bit_special_class(word16* w) {
  return w->get_bits(15, 10) == special16_class_v;
}

bool arm_disassembler::is_16_bit_add(word16* w) {
  return w->get_bits(13, 9) == add16_v;
}

bool arm_disassembler::is_special_add16(word16* w) {
  return w->get_bits(9, 8) == special_add16_v;
}

bool arm_disassembler::is_start_of_32_bit_instruction(word16& w) {
  std::vector<bit> w_header = w.get_bits(15, 11);
  return w_header == vp1 || w_header == vp2 || w_header == vp3;
}

std::unique_ptr<arm_instruction_sequence> arm_disassembler::disassembleARM6M(unsigned int start_addr, endianness end, const char* bytes, unsigned int n) {
  std::cout << "DEBUG: n = " << std::to_string(n) << std::endl;
  auto word16_list = convert_to_word16(end, bytes, n);
  auto instrs = new arm_instruction_sequence(start_addr);
  int i = 0;
  while (i < word16_list.size()) {
    if (is_start_of_32_bit_instruction(*(word16_list[i]))) {
      instrs->add_instruction(*(word16_list[i]), *(word16_list[i+1]));
      i += 2;
    } else {
      instrs->add_instruction(*(word16_list[i]));
      i += 1;
    }
  }
  return std::unique_ptr<arm_instruction_sequence>(instrs);
}
