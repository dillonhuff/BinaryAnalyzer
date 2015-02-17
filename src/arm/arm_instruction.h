#ifndef ARM_INSTRUCTION_H_
#define ARM_INSTRUCTION_H_

#include <vector>

#include "utils/word16.h"
#include "utils/bit.h"

enum instruction_width { HALFWORD, FULLWORD };

class arm_instruction {
 private:
  instruction_width width;
  std::vector<bit> bits;
  std::vector<char> bytes;

 public:
  arm_instruction(word16& word);
  arm_instruction(word16& word1, word16& word2);
  
  unsigned int get_byte_width();
  std::string raw_bits_to_string();
  std::string hex_string();
  std::string assembly_string();
};

#endif
