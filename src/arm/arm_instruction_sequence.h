#ifndef ARM_INSTRUCTION_SEQUENCE_H_
#define ARM_INSTRUCTION_SEQUENCE_H_

#include <memory>
#include <vector>
#include <string>

#include "arm/arm_instruction.h"
#include "utils/word32.h"

class arm_instruction_sequence {
 private:
  std::vector<std::unique_ptr<arm_instruction>> instructions;

 public:
  void add_instruction(word32& word);
  std::string raw_bits_to_string();
};

#endif
