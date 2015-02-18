#include "bit_field.h"

bit_field::bit_field(std::vector<bit> b) {
  bits = b;
}

bit bit_field::operator[](unsigned int i) {
  return bits[i];
}

unsigned int bit_field::size() {
  return bits.size();
}

bit_field bit_field::subfield(unsigned int top, unsigned int bottom) {
  std::vector<bit> bs;
  unsigned int i = top;
  for (unsigned int k = 0; k <= top - bottom; k++) {
    bs.push_back(bits[i]);
    i--;
  }
  return bit_field(bs);
}
