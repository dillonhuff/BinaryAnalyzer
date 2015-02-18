#include "arm/mnemonic_decoder.h"

mnemonic_decoder::mnemonic_decoder(std::string name) {
  mnemonic = name;
}

unsigned int mnemonic_decoder::decode(arm_instruction* instr, bit_field* bits) {
  instr->set_mnemonic(mnemonic);
  return 0;
}
