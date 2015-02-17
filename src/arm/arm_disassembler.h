#ifndef ARM_DISASSEMBLER_H_
#define ARM_DISASSEMBLER_H_

#include <memory>
#include <vector>

#include "arm/arm_instruction_sequence.h"
#include "utils/endianness.h"

class arm_disassembler {
 private:
  static bool is_start_of_32_bit_instruction(word16& w);

 public:
  static std::unique_ptr<arm_instruction_sequence> disassembleARM6M(unsigned int start_address, endianness end, const char* bytes, unsigned int n);
};

#endif
