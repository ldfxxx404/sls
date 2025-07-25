#include <algorithm>
#include <vector>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include "filePermission.hpp"
#include "typeCheck.hpp"

std::filesystem::path directoryPath;

int check_type_of_file(int argc, char *argv[])
{
    argc > 1 ? directoryPath = argv[1] : directoryPath = ".";

    try
    {
        std::vector<std::filesystem::directory_entry> entries;
        for (const auto &entry : std::filesystem::directory_iterator(directoryPath))
        {
            entries.push_back(entry);
        }

        std::sort(entries.begin(), entries.end(), [](const std::filesystem::directory_entry &a, const std::filesystem::directory_entry &b)
                  { return a.path().filename() < b.path().filename(); });

        for (const auto &entry : entries)
        {
            std::cout << std::left << std::setw(22) << entry.path().filename();

            if (std::filesystem::is_regular_file(entry.path()))
            {
                std::cout << std::left << std::setw(10) << "\x1B[93mFile\033[0m" << " ";
            }

            else if (std::filesystem::is_directory(entry.path()))
            {
                std::cout << std::left << std::setw(10) << "\x1B[36mDir\033[0m" << " ";
            }
            check_file_permission(entry.path());
        }
    }

    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}