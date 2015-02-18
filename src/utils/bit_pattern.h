#ifndef BIT_PATTERN_H_
#define BIT_PATTERN_H_

#include <vector>

#include "bit.h"
#include "bit_field.h"

enum bit_p { one, zero, any };

class bit_pattern {
 private:
  std::vector<bit_p> pattern;

 public:
  bit_pattern(bit_p* pat, int n);
  bool matches(bit_field bits);
};

#endif
