#include <assert.h>
#include <iostream>

#include "utils/endianness.h"
#include "utils/word32.h"

std::vector<std::unique_ptr<word32>> convert_to_word32(endianness end, const char* bytes, unsigned int n) {
  assert(n % 4 == 0);

  std::vector<std::unique_ptr<word32>> words;
  return words;
}
