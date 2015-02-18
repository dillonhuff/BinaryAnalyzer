#ifndef INSTRUCTION_PROCESSOR_H_
#define INSTRUCTION_PROCESSOR_H_

#include "arm/arm_instruction.h"
#include "utils/bit_field.h"

class instruction_processor {
 public:
  virtual void process(arm_instruction* instr, bit_field* bits);
};
#endif
