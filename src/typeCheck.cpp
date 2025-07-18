#include "typeCheck.hpp"
#include <filesystem>
#include <iostream>

std::filesystem::path directoryPath;

int check(int argc, char *argv[])
{

    if (argc > 1)
    {
        directoryPath = argv[1];
    }
    else
    {
        directoryPath = ".";
    }

    try
    {
        for (const auto &entry : std::filesystem::directory_iterator(directoryPath))
        {

            std::cout << entry.path().filename() << " ";

            if (std::filesystem::is_regular_file(entry.path()))
            {

                std::cout << "\x1B[93m(File)\033[0m" << std::endl;
            }
            else if (std::filesystem::is_directory(entry.path()))
            {

                std::cout << "\x1B[36m(Directory)\033[0m" << std::endl;
            }
        }
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}