#include <iostream>

#include "arm/arm_disassembler.h"
#include "elfio/elfio.hpp"
#include "utils/bit_pattern_table.hpp"
#include "utils/hex_print.h"
#include "utils/word16_tests.h"

using namespace ELFIO;

void disassemble_code(char* elf_file_name);
void print_symbols(elfio* reader, section* symbol_sec);
void print_symtabs(elfio* reader);
void read_elf(char* elf_file_name);
void run_all_tests();

int main(int argc, char** argv) {
  if (argc == 1) {
    run_all_tests();
  } else if (argc == 2) {
    disassemble_code(argv[1]);
  } else {
    std::cout << "Usage: ./tests <efl_file_name>" << std::endl;
    std::cout << "Or   : ./tests to run all tests" << std::endl;
  }
  return 0;
}
void run_all_tests() {
  std::cout << "------------------- All Tests --------------------" << std::endl;
  all_word16_tests();
  std::cout << "--------------------------------------------------" << std::endl;
}

void disassemble_code(char* elf_file_name) {
  elfio reader;

  if (!reader.load(elf_file_name)) {
    std::cout << "Can't find or process the ELF file " << elf_file_name << std::endl;
  }

  section* text_section = NULL;  
  for (auto sec : reader.sections) {
    if (sec->get_name() == ".text") {
      text_section = sec;
    }
  }
  
  if (text_section == NULL) {
    std::cout << elf_file_name << " has no .text section" << std::endl;
    return;
  }

  std::cout << "text_section address: " << hex_num_to_string(8, ' ', text_section->get_address()) << std::endl;
  std::cout << "text_section size: " << std::to_string(text_section->get_size()) << std::endl;
  auto instructions = arm_disassembler::disassembleARM6M(text_section->get_address(), LITTLE, (unsigned char*) text_section->get_data(), (unsigned int) text_section->get_size());
  std::cout << instructions->instruction_codes_to_string() << std::endl;
}

void read_elf(char* elf_file_name) {

  elfio reader;
  if (!reader.load(elf_file_name)) {
    std::cout << "Can't find or process the ELF file " << elf_file_name << std::endl;
  }

  std::cout << "ELF file class: ";
  if (reader.get_class() == ELFCLASS32) {
    std::cout << "ELF32" << std::endl;
  } else {
    std::cout << "ELF64" << std::endl;
  }

  std::cout << "File encoding: ";
  if (reader.get_encoding() == ELFDATA2LSB) {
    std::cout << "Little endian" << std::endl;
  } else {
    std::cout << "Big endian" << std::endl;
  }

  Elf_Half sec_num = reader.sections.size();
  std::cout << "Number of sections: " << sec_num << std::endl;
  for (int i = 0; i < sec_num; i++) {
    const section* psec = reader.sections[i];
    std::cout << " [" << i << "] "
	      << psec->get_name()
	      << "\t"
	      << psec->get_size()
	      << std::endl;
  }

  Elf_Half seg_num = reader.segments.size();
  std::cout << "Number of segments: " << seg_num << std::endl;
  for (int i = 0; i < seg_num; i++) {
    const segment* pseg = reader.segments[i];
    std::cout << " [" << i << "] "
	      << pseg->get_flags()
	      << "\t0x"
	      << pseg->get_virtual_address()
	      << "\t0x"
	      << pseg->get_file_size()
	      << "\t0x"
	      << pseg->get_memory_size()
	      << std::endl;
  }

  print_symtabs(&reader);
}

void print_symbols(elfio* reader, section* symtab_sec) {
  const symbol_section_accessor symbols(*reader, symtab_sec);
  for (unsigned int i = 0; i < symbols.get_symbols_num(); i++) {
    std::string name;
    Elf64_Addr value;
    Elf_Xword size;
    unsigned char bind;
    unsigned char type;
    Elf_Half section_index;
    unsigned char other;
    symbols.get_symbol(i, name, value, size, bind, type, section_index, other);
    std::cout << i << " " << name << std::endl;
  }
}

void print_symtabs(elfio* reader) {
  for (auto sec : reader->sections) {
    if (sec->get_type() == SHT_SYMTAB) {
      std::cout << "symbols" << std::endl;
      print_symbols(reader, sec);
    }
  }
}
