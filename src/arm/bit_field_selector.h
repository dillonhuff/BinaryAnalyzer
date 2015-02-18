#ifndef BIT_FIELD_SELECTOR_H_
#define BIT_FIELD_SELECTOR_H_

#include "arm/arm_instruction.h"
#include "utils/bit_field.h"

class bit_field_selector {
 public:
  virtual bit_field select_bits(arm_instruction* instr, bit_field* bits);
};
#endif
