#include <assert.h>
#include <iostream>

#include "utils/endianness.h"
#include "utils/word32.h"

word32::word32(endianness end, const char* bytes) {
  endian = end;
  b0 = bytes[0];
  b1 = bytes[1];
  b2 = bytes[2];
  b3 = bytes[3];
}

std::vector<std::unique_ptr<word32>> convert_to_word32(endianness end, const char* bytes, unsigned int n) {
  assert(n % 4 == 0);

  std::vector<std::unique_ptr<word32>> words;
  unsigned int num_words = n / 4;
  for (unsigned int i = 0; i < num_words; i += 4) {
    words.push_back(std::unique_ptr<word32>(new word32(end, &bytes[i])));
  }
  return words;
}
