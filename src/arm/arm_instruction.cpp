#include "arm/arm_instruction.h"

arm_instruction::arm_instruction(word16& word) {
  width = HALFWORD;
  bits = word.get_bits(15, 0);
  bytes.push_back(word.most_sig_byte());
  bytes.push_back(word.least_sig_byte());
}

arm_instruction::arm_instruction(word16& word1, word16& word2) {
  width = FULLWORD;
  bits = word1.get_bits(15, 0);
  int i = 15;
  for (int j = 0; j < 15; j++) {
    bits.push_back(word2.get_bit(i));
  }

  bytes.push_back(word1.most_sig_byte());
  bytes.push_back(word1.least_sig_byte());
  bytes.push_back(word2.most_sig_byte());
  bytes.push_back(word2.least_sig_byte());
}

unsigned int arm_instruction::get_width() {
  return width == HALFWORD ? 16 : 32;
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
