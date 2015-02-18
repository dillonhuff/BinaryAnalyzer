#ifndef NO_OP_DECODER_H_
#define NO_OP_DECODER_H_

#include "decoder.h"

class noop_decoder : public decoder {
 public:
  virtual unsigned int decode(arm_instruction* instr, bit_field* bits) { return 0; }
};

#endif
