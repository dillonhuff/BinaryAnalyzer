#include "arm_disassembler.h"
#include "utils/word16.h"

#include <iostream>

std::unique_ptr<arm_instruction_sequence> arm_disassembler::disassemble32(unsigned int start_addr, endianness end, const char* bytes, unsigned int n) {
  std::cout << "DEBUG: n = " << std::to_string(n) << std::endl;
  auto word32_list = convert_to_word16(end, bytes, n);
  auto instrs = new arm_instruction_sequence();
  for (auto& word : word32_list) {
    instrs->add_instruction(*word);
  }
  return std::unique_ptr<arm_instruction_sequence>(instrs);
}
