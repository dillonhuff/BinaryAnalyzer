#ifndef CLASS_32_BIT_SELECTOR_H_
#define CLASS_32_BIT_SELECTOR_H_

#include "arm/bit_field_selector.h"

class class_32_bit_selector : public bit_field_selector {
 public:
  virtual bit_field select_bits(arm_instruction* instr, bit_field* bits) { return bits->subfield(28, 15); }
};

#endif
