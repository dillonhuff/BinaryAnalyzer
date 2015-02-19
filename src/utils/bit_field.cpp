#include <assert.h>

#include "bit_field.h"

bit_field::bit_field(std::vector<bit> b) {
  bits = b;
}

bit bit_field::operator[](unsigned int i) {
  return get_bit(i);
}

bit bit_field::get_bit(unsigned int i) {
  assert(this->size() > i && i >= 0);
  return bits[this->size() - i];
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

std::string bit_field::to_string() {
  std::string result = "";
  for (unsigned int i = 0; i < bits.size(); i++) {
    if (get_bit(i) == ONE) {
      result += "1";
    } else {
      result += "0";
    }
  }
  return result;
}
