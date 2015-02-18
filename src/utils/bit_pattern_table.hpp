#ifndef BIT_PATTERN_TABLE_H_
#define BIT_PATTERN_TABLE_H_

#include <iostream>
#include <utility>
#include <vector>

#include "bit_pattern.h"

template <class T>
class bit_pattern_table {
  private:
  std::vector<std::pair<bit_pattern, T>> patterns;

  public:
  bit_pattern_table(bit_p** pats, T* res, int n, int pat_len) {
    for (int i = 0; i < n; i++) {
      auto p = std::pair<bit_pattern, T>(bit_pattern(pats[i], pat_len), res[i]);
      patterns.push_back(p);
    }
  }

  T match(std::vector<bit> bits) {
    for (auto p : patterns) {
      if (p.first.matches(bits)) {
	return p.second;
      }
    }
    std::cout << "ERROR: No pattern match" << std::endl;
    throw;
  }
};

#endif
