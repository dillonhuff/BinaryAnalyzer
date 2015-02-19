#include <iostream>

#include "arm/instruction_processor.h"

void instruction_processor::process(arm_instruction* instr, bit_field* bits) {
  std::cout << "Error: instruction::proccessor::process called" << std::endl;
  throw;
}
