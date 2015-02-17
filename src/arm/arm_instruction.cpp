#include "arm/arm_instruction.h"

arm_instruction::arm_instruction(word16& word) {
  bits = word.get_bits(15, 0);
}

std::string arm_instruction::raw_bits_to_string() {
  std::string bit_string = "";
  for (int i = 0; i < 16; i++) {
    bit b = bits[i];
    if (b == ZERO) {
      bit_string += "0";
    } else {
      bit_string += "1";
    }
    if (i % 4 == 3) {
      bit_string += " ";
    }
  }
  return bit_string;
}
