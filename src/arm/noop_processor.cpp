#include <iostream>

#include "arm/noop_processor.h"

void noop_processor::process(arm_instruction* instr, bit_field* bits) {
  std::cout << "noop process called" << std::endl;
  return;
}
