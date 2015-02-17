#ifndef ARM_INSTRUCTION_SEQUENCE_H_
#define ARM_INSTRUCTION_SEQUENCE_H_

#include <memory>
#include <vector>
#include <string>

#include "arm/arm_instruction.h"

class arm_instruction_sequence {
 private:
  std::vector<std::unique_ptr<arm_instruction>> instructions;

 public:
  std::string to_string();
};

#endif
