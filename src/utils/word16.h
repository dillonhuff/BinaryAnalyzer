#ifndef WORD_16_H
#define WORD_16_H

#include <memory>
#include <vector>

#include "utils/bit.h"
#include "utils/endianness.h"

class word16 {
 private:
  endianness endian;
  std::vector<char> bytes;

 public:
  word16(endianness end, const char* b);

  bit get_bit(unsigned int index);
  std::vector<bit> get_bits(unsigned int top, unsigned int bottom);

  std::string to_hex_string();
};

std::vector<std::unique_ptr<word16>> convert_to_word16(endianness end, const char* bytes, unsigned int n);

#endif
