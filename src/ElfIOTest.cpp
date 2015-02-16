#include <iostream>
#include "elfio/elfio.hpp"

using namespace ELFIO;

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: tutorial <elf_file>" << std::endl;
  }
  return 0;
}
