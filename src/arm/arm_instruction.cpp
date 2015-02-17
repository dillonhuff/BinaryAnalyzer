#include "arm/arm_instruction.h"

arm_instruction::arm_instruction(word32& word) {
  bits = word.get_bits(31, 0);
}

std::string arm_instruction::bits_to_string() {
  std::string bit_string = "";
  for (auto b : bits) {
    if (b == ZERO) {
      bit_string += "0";
    } else {
      bit_string += "1";
    }
  }
  return bit_string;
}
