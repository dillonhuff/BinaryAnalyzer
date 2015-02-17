#include "arm_disassembler.h"
#include "utils/word16.h"

#include <iostream>

bool arm_disassembler::is_start_of_32_bit_instruction(word16& w) {
  return false;
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
