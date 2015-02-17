#include <assert.h>
#include <iostream>

#include "utils/endianness.h"
#include "utils/word16.h"

word16::word16(endianness end, const char* b) {
  endian = end;
  bytes.push_back(b[0]);
  bytes.push_back(b[1]);
}

bit word16::get_bit(unsigned int index) {
  assert(31 >= index && index >= 0);
  if (endian == LITTLE) {
    unsigned int byte_num = index / 8;
    unsigned int byte_index = index % 8;
    unsigned int bit_val = (bytes[byte_num] >> byte_index) & 0x01;
    return bit_val == 1 ? ONE : ZERO;
  } else {
    throw;
  }
}

std::vector<bit> word16::get_bits(unsigned int top, unsigned int bottom) {
  assert(top >= bottom);
  assert(31 >= top && top >= 0);
  assert(31 >= bottom && bottom >= 0);

  std::vector<bit> bits;
  unsigned int i = top;
  for (int k = 0; k <= top - bottom; k++) {
    bits.push_back(get_bit(i));
    i--;
  }
  return bits;
}

std::string word16::to_hex_string() {
  assert(bytes.size() == 2);
  if (endian == LITTLE) {
    return hex_to_string(2, '0', bytes[1]) + hex_to_string(2, '0', bytes[0]);
  }
}

std::vector<std::unique_ptr<word16>> convert_to_word16(endianness end, const char* bytes, unsigned int n) {
  assert(n % 2 == 0);

  std::vector<std::unique_ptr<word16>> words;
  unsigned int num_words = n;
  for (unsigned int i = 0; i < num_words; i += 2) {
    words.push_back(std::unique_ptr<word16>(new word16(end, &bytes[i])));
  }
  return words;
}

