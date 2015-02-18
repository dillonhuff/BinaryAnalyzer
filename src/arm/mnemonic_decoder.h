#ifndef MNEMONIC_DECODER_H_
#define MNEMONIC_DECODER_H_

#include <string>

#include "arm/decoder.h"

class mnemonic_decoder : public decoder {
 private:
  std::string mnemonic;

 public:
  mnemonic_decoder(std::string name);
  virtual unsigned int decode(arm_instruction* instr, bit_field* bits);
};

#endif
