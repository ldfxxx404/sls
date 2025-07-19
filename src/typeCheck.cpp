#include "typeCheck.hpp"
#include <filesystem>
#include <iostream>
#include "filePermission.hpp"

std::filesystem::path directoryPath;

int check_type_of_file(int argc, char *argv[])
{
    argc > 1 ? directoryPath = argv[1] : directoryPath = ".";

    try
    {
        for (const auto &entry : std::filesystem::directory_iterator(directoryPath))
        {

            std::cout << entry.path().filename() << " ";

            if (std::filesystem::is_regular_file(entry.path()))
            {
                std::cout << "\x1B[93m(File)\033[0m" << " ";
                check_file_permission(entry.path());
            }
            else if (std::filesystem::is_directory(entry.path()))
            {
                std::cout << "\x1B[36m(Directory)\033[0m" << " ";
                check_file_permission(entry.path());
            }
        }
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}