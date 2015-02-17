#ifndef WORD_32_H_
#define WORD_32_H_

#include <memory>
#include <vector>

class word32 {

};

std::vector<std::unique_ptr<word32>> convert_to_word32(Endianness end, const char* bytes);
#endif
