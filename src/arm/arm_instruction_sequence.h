#ifndef ARM_INSTRUCTION_SEQUENCE_H_
#define ARM_INSTRUCTION_SEQUENCE_H_

#include <memory>
#include <vector>
#include <string>

#include "arm/arm_instruction.h"
#include "utils/word16.h"

class arm_instruction_sequence {
 private:
  unsigned int start_address;
  std::vector<std::unique_ptr<arm_instruction>> instructions;

 public:
  void add_instruction(word16& word);
  std::string raw_bits_to_string();
};

#endif
