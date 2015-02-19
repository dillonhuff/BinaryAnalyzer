#include <iostream>

#include "bit_pattern.h"

bit_pattern::bit_pattern(bit_p* pat, int n) {
  for (int i = 0; i < n; i++) {
    pattern.push_back(pat[i]);
  }
}

bool bit_pattern::matches(bit_field bits) {
  if (bits.size() != pattern.size()) {
    std::cout << "Trying to match uneven size patterns" << std::endl;
    throw;
  }
  for (unsigned int i = 0; i < bits.size(); i++) {
    if ((pattern[i] != any) &&
	((bits[i] == ONE && pattern[i] == zero) ||
	 (bits[i] == ZERO && pattern[i] == one))) {
      std::cout << "Match failed, bits: " << std::endl;
      std::cout << bits.to_string() << std::endl;
      return false;
    }
  }
  return true;
}
