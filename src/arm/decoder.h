#ifndef DECODER_H_
#define DECODER_H_

#include "arm/arm_instruction.h"
#include "utils/bit_field.h"

class decoder {
 public:
  virtual unsigned int decode(arm_instruction* instr, bit_field* bits);
};

#endif
