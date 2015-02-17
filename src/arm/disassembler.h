#include <memory>

#ifndef DISASSEMBLER_H_
#define DISASSEMBLER_H_

class disassembler {
 public:
  static unique_ptr<arm_instruction_sequence> disassemble32(Endianness end, char* bytes);
};

#endif DISASSEMBLER
