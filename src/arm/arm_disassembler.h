#ifndef ARM_DISASSEMBLER_H_
#define ARM_DISASSEMBLER_H_

#include <memory>
#include <vector>

#include "arm/arm_instruction_sequence.h"
#include "utils/endianness.h"

class arm_disassembler {
 public:
  static std::unique_ptr<arm_instruction_sequence> disassemble32(endianness end, const char* bytes);
};

#endif
