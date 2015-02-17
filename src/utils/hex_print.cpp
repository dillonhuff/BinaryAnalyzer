#include <assert.h>
#include <iomanip>
#include <iostream>
#include <sstream>

std::string hex_to_string(unsigned int width, char filler, char hex_char) {
  std::stringstream stream;
  stream << std::setw(width) << std::setfill(filler) << std::hex << (((int) hex_char) & 0xff);
  std::string result(stream.str());
  return result;
}
