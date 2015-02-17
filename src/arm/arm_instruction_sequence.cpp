#include "arm/arm_instruction_sequence.h"

void arm_instruction_sequence::add_instruction(word32& word) {
  auto new_instr = new arm_instruction(word);
  instructions.push_back(std::unique_ptr<arm_instruction>(new_instr));
}

std::string arm_instruction_sequence::to_string() {
  std::string instruction_string = "";
  for (auto& instr : instructions) {
    
  }
  return instruction_string;
}
