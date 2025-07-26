#include "filePermission.hpp"
#include "typeCheck.hpp"
#include <filesystem>
#include <iostream>

int main(int argc, char *argv[]) {

  check_type_of_file(argc, argv);
  return 0;
}
