#include <iostream>

#include "bit_pattern.h"

bit_pattern::bit_pattern(bit_p* pat, int n) {
  for (int i = 0; i < n; i++) {
    pattern.push_back(pat[i]);
  }
}

bool bit_pattern::matches(std::vector<bit> bits) {
  if (bits.size() != pattern.size()) {
    std::cout << "Trying to match uneven size patterns" << std::endl;
    throw;
  }
  for (unsigned int i = 0; i < bits.size(); i++) {
    if ((pattern[i] != any) &&
	((bits[i] == ONE && pattern[i] == zero) ||
	 (bits[i] == ZERO && pattern[i] == one))) {
      std::cout << "Bit match failed at " << i << std::endl;
      std::cout << "Bit vector:" << std::endl;
      for (auto b : bits) {
	std::cout << b;
      }
      std::cout << std::endl;
      return false;
    }
  }
  return true;
}
