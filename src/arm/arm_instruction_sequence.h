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
  arm_instruction_sequence(unsigned int start_address);

  void add_instruction(word16& word);
  void add_instruction(word16& word1, word16& word2);

  std::string raw_bits_to_string();
  std::string instruction_codes_to_string();
};

#endif
