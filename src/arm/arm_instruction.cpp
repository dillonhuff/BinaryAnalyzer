#include "arm/arm_instruction.h"

arm_instruction::arm_instruction(word32& word) {
  bits = word.get_bits(31, 0);
}

std::string arm_instruction::raw_bits_to_string() {
  std::string bit_string = "";
  for (int i = 0; i < 32; i++) {
    b = bits[i];
    if (b == ZERO) {
      bit_string += "0";
    } else {
      bit_string += "1";
    }
    if (i % 4 = 0 && i > 0) {
      bit_string += " ";
    }
  }
  return bit_string;
}
