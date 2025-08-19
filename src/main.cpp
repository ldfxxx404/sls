#include <filesystem>
#include <iostream>

#include "filePermission.hpp"
#include "typeCheck.hpp"

int main(int argc, char *argv[]) {
    check_type_of_file(argc, argv);
    return 0;
}
