#ifndef WORD_32_H_
#define WORD_32_H_

#include <memory>
#include <vector>

#include "utils/bit.h"
#include "utils/endianness.h"

class word32 {
 private:
  endianness endian;
  std::vector<char> bytes;

 public:
  word32(endianness end, const char* b);
  bit get_bit(unsigned int index);
  std::vector<bit> get_bits(unsigned int top, unsigned int bottom);
};

std::vector<std::unique_ptr<word32>> convert_to_word32(endianness end, const char* bytes, unsigned int n);
#endif
