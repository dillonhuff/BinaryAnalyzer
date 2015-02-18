#include "arm/table_decoder.h"

unsigned int table_decoder::decode(arm_instruction* instr, bit_field* bits) {
  action(instr, bits);
  auto next_decoder = children.match(bit_field_to_match(instr, bits));
  return next_decoder->decode(instr, bits);
}
