#include "arm/arm_instruction_sequence.h"
#include "utils/hex_print.h"

arm_instruction_sequence::arm_instruction_sequence(unsigned int start_addr) {
  start_address = start_addr;
}

void arm_instruction_sequence::add_instruction(word16& word) {
  auto new_instr = new arm_instruction(word);
  instructions.push_back(std::unique_ptr<arm_instruction>(new_instr));
}

void arm_instruction_sequence::add_instruction(word16& word1, word16& word2) {
  auto new_instr = new arm_instruction(word1, word2);
  instructions.push_back(std::unique_ptr<arm_instruction>(new_instr));
}

std::string arm_instruction_sequence::raw_bits_to_string() {
  std::string instruction_string = "";
  instruction_string += "# of Instructions: " + std::to_string(instructions.size()) + "\n";
  instruction_string += "# of Bytes: " + std::to_string(instructions.size() * 4) + "\n";
  for (auto& instr : instructions) {
    instruction_string += instr->raw_bits_to_string() + "\n";
  }
  return instruction_string;
}

std::string arm_instruction_sequence::instruction_codes_to_string() {
  std::string instruction_string = "";
  instruction_string += "# of Instructions: " + std::to_string(instructions.size()) + "\n";
  instruction_string += "# of Bytes: " + std::to_string(instructions.size() * 4) + "\n";
  unsigned int instr_addr = start_address;
  for (auto& instr : instructions) {
    instruction_string += hex_num_to_string(8, ' ', instr_addr) + ":\t";
    instruction_string += instr->hex_string() + "\t";
    instruction_string += instr->assembly_string() + "\n";
    instr_addr += instr->get_byte_width();
  }
  return instruction_string;

}
