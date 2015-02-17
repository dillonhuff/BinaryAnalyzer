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
  static bool is_16_bit_shift_class(word16* w);
  static bool is_16_bit_special_class(word16* w);

  static bool is_16_bit_add(word16* w);
  static bool is_special_add16(word16* w);

  static std::unique_ptr<arm_instruction_sequence> disassembleARM6M(unsigned int start_address, endianness end, const char* bytes, unsigned int n);
};

#endif
