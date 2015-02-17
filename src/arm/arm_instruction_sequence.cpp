#include "arm/arm_instruction_sequence.h"

void arm_instruction_sequence::add_instruction(word32& word) {
  auto new_instr = new arm_instruction(word);
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
