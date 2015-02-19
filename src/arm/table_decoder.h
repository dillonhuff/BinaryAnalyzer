#ifndef TABLE_DECODER_H_
#define TABLE_DECODER_H_

#include "arm/bit_field_selector.h"
#include "arm/decoder.h"
#include "arm/instruction_processor.h"
#include "utils/bit_pattern_table.hpp"

class table_decoder : public decoder {
 private:
  bit_pattern_table<decoder*>* children;
  instruction_processor* processor;
  bit_field_selector* selector;

 public:
  table_decoder(instruction_processor* proc, bit_field_selector* sel, bit_pattern_table<decoder*>* child_table);
  virtual unsigned int decode(arm_instruction* instr, bit_field* bits);
};

#endif
