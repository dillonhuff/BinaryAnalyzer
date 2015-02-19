#include <iostream>

#include "arm/bit_field_selector.h"

bit_field bit_field_selector::select_bits(arm_instruction* instr, bit_field* bits) {
  std::cout << "Error: bit_field_selector::select_bits called" << std::endl;
  throw;
}
