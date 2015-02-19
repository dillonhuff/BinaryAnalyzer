#include <iostream>

#include "arm/decoder.h"

unsigned int decoder::decode(arm_instruction* instr, bit_field* bits) {
  std::cout << "Error: attempt to call decoder::decode" << std::endl;
  throw;
}
