#include <iostream>

#include "utils/bit_pattern.h"
#include "utils/word16.h"
#include "test/test_utils/test_reports.h"
#include "test/utils/word16_tests.h"

void first_bit_printout() {
  if (SYSTEM_ENDIANNESS == LITTLE) {
    const unsigned char bytes[2] = {0x01, 0x00};
    const unsigned char* bs = bytes;
    auto word = word16{SYSTEM_ENDIANNESS, bs};
    test_result(word.to_hex_string() == "0001", "first bit printout", "first bit printout is not one");
  } else {
    const unsigned char bytes[2] = {0x00, 0x01};
    const unsigned char* bs = bytes;
    auto word = word16{SYSTEM_ENDIANNESS, bs};
    test_result(word.to_hex_string() == "0001", "first bit printout", "first bit printout is not one");
  }
}

void first_bit_value() {
  if (SYSTEM_ENDIANNESS == LITTLE) {
    const unsigned char bytes[2] = {0x01, 0x00};
    const unsigned char* bs = bytes;
    auto word = word16{SYSTEM_ENDIANNESS, bs};
    test_result(word.get_bit(0) == ONE, "first bit value", "first bit of 0x0001 not one");
  } else {
    const unsigned char bytes[2] = {0x00, 0x01};
    const unsigned char* bs = bytes;
    auto word = word16{SYSTEM_ENDIANNESS, bs};
    test_result(word.get_bit(0) == ONE, "first bit value", "first bit of 0x0001 is not one");
  }
}

void last_bit_value() {
  if (SYSTEM_ENDIANNESS == LITTLE) {
    const unsigned char bytes[2] = {0x00, 0x80};
    const unsigned char* bs = bytes;
    auto word = word16{SYSTEM_ENDIANNESS, bs};
    test_result(word.get_bit(15) == ONE, "last bit value", "last bit of 0x8000 not one");
  } else {
    const unsigned char bytes[2] = {0x80, 0x00};
    const unsigned char* bs = bytes;
    auto word = word16{SYSTEM_ENDIANNESS, bs};
    test_result(word.get_bit(15) == ONE, "last bit value", "last bit of 0x8000 is not one");
  }
}

void pattern_match() {
  if (SYSTEM_ENDIANNESS == LITTLE) {
    const unsigned char bytes[2] = {0x4f, 0xf0};
    const unsigned char* bs = bytes;
    auto word = word16{SYSTEM_ENDIANNESS, bs};
    auto w_b = word.get_bits(15, 11);
    bit_p pat_b[5] = {one, one, one, one, zero};
    auto pat = bit_pattern{pat_b, 5};
    test_result(pat.matches(w_b), "32 bit instruction match", "instruction code matching 32 bits doesn't match 32 bit pattern");
  } else {
    std::cout << "No test for big endian system yet\n";
    throw;
  }
}

void all_word16_tests() {
  std::cout << "----------------- word16 tests -------------------" << std::endl;
  first_bit_printout();
  first_bit_value();
  last_bit_value();
  std::cout << "--------------------------------------------------" << std::endl;
}
