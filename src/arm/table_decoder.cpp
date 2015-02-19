#include "arm/table_decoder.h"

table_decoder::table_decoder(instruction_processor* proc, bit_field_selector* sel, bit_pattern_table<decoder*>* child_table) {
  processor = proc;
  selector = sel;
  children = child_table;
}

unsigned int table_decoder::decode(arm_instruction* instr, bit_field* bits) {
  processor->process(instr, bits);
  auto next_decoder = children->match(selector->select_bits(instr, bits));
  return next_decoder->decode(instr, bits);
}
