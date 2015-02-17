#include "arm_disassembler.h"
#include "utils/word32.h"

#include <iostream>

std::unique_ptr<arm_instruction_sequence> arm_disassembler::disassemble32(endianness end, const char* bytes, unsigned int n) {
  std::cout << "DEBUG: n = " << std::to_string(n) << std::endl;
  auto word32_list = convert_to_word32(end, bytes, n);
  auto instrs = new arm_instruction_sequence();
  for (auto& word : word32_list) {
    instrs->add_instruction(*word);
  }
  return std::unique_ptr<arm_instruction_sequence>(instrs);
}
