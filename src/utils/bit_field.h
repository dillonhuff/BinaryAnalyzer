#ifndef BIT_FIELD_H_
#define BIT_FIELD_H_

#include <string>
#include <vector>

#include "utils/bit.h"

class bit_field {
 private:
  std::vector<bit> bits;

 public:
  bit_field(std::vector<bit> b);
  bit operator[](unsigned int i);
  bit get_bit(unsigned int i);
  bit_field subfield(unsigned int top, unsigned int bottom);
  unsigned int size();

  std::string to_string();
};

#endif
