#include "arm_disassembler.h"
#include "utils/word32.h"

std::unique_ptr<arm_instruction_sequence> arm_disassembler::disassemble32(endianness end, const char* bytes, unsigned int n) {
  auto word32_list = convert_to_word32(end, bytes, n);
  auto instrs = new arm_instruction_sequence();
  return std::unique_ptr<arm_instruction_sequence>(instrs);
}
