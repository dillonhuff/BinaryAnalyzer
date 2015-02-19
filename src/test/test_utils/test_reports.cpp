#include <iostream>
#include <string>

//#include "test_utils/test_reports.h"

void test_result(bool result, std::string test_name, std::string fail_msg) {
  if (result) {
    std::cout << test_name << " passed" << std::endl;
  } else {
    std::cout << test_name << " FAILED: " << fail_msg << std::endl;
  }
}
