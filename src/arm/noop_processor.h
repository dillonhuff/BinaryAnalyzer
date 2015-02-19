#ifndef NOOP_PROCESSOR_H_
#define NOOP_PROCESSOR_H_

#include "arm/instruction_processor.h"

class noop_processor : public instruction_processor {
 public:
  virtual void process(arm_instruction* instr, bit_field* bits);
};

#endif
