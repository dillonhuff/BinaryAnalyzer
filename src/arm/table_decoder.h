#ifndef TABLE_DECODER_H_
#define TABLE_DECODER_H_

#include "arm/decoder.h"
#include "utils/bit_pattern_table.hpp"

class table_decoder : public decoder {
 private:
  bit_pattern_table<decoder*> children;

  virtual void action(arm_instruction* instr, bit_field* bits) = 0;
  virtual bit_field bit_field_to_match(arm_instruction* instr, bit_field* bits) = 0;

 public:
  virtual unsigned int decode(arm_instruction* instr, bit_field* bits);
};

#endif
