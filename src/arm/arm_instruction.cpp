#include "arm/arm_instruction.h"
#include "arm/arm_disassembler.h"
#include "utils/hex_print.h"

arm_instruction::arm_instruction(word16* word) {
  mnemonic = "UNRECOGNIZED";
  instr_class = "";
  width = HALFWORD;
  bits = word->get_bits(15, 0);
  bytes.push_back(word->most_sig_byte());
  bytes.push_back(word->least_sig_byte());
}

arm_instruction::arm_instruction(word16* word1, word16* word2) {
  mnemonic = "UNRECOGNIZED";
  instr_class = "";
  width = FULLWORD;
  bits = word1->get_bits(15, 0);
  int i = 15;
  for (int j = 0; j < 15; j++) {
    bits.push_back(word2->get_bit(i));
  }

  bytes.push_back(word1->most_sig_byte());
  bytes.push_back(word1->least_sig_byte());
  bytes.push_back(word2->most_sig_byte());
  bytes.push_back(word2->least_sig_byte());
}

unsigned int arm_instruction::get_byte_width() {
  return width == HALFWORD ? 2 : 4;
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

std::string arm_instruction::hex_string() {
  if (width == HALFWORD) {
    return hex_char_to_string(2, '0', bytes[0]) + hex_char_to_string(2, '0', bytes[1]);
  } else {
    return hex_char_to_string(2, '0', bytes[0]) + hex_char_to_string(2, '0', bytes[1]) + " " + hex_char_to_string(2, '0', bytes[2]) + hex_char_to_string(2, '0', bytes[3]);
  }
}

std::string arm_instruction::assembly_string() {
  return mnemonic + " " + instr_class;
}

void arm_instruction::set_class(std::string new_class) {
  instr_class = new_class;
}
