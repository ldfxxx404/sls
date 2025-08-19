#include "filePermission.hpp"

#include <filesystem>
#include <iostream>

void check_file_permission(const std::filesystem::path &path) {
    using std::filesystem::perms;
    auto file_permisson = std::filesystem::status(path).permissions();

    auto show = [file_permisson](char r, perms p) {
        std::cout << ((file_permisson & p) != perms::none ? r : '-');
    };

    show('r', perms::owner_read);
    show('w', perms::owner_write);
    show('x', perms::owner_exec);
    show('r', perms::group_read);
    show('w', perms::group_write);
    show('x', perms::group_exec);
    show('r', perms::others_read);
    show('w', perms::others_write);
    show('x', perms::others_exec);
    std::cout << '\n';
}