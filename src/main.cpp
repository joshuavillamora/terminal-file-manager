#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::path currentPath = "/";

    for (const auto& entry : std::filesystem::directory_iterator(currentPath)) {
        std::cout << entry.path().filename().string();

        if (entry.is_directory()) {
            std::cout << "/";
        }

        std::cout << '\n';
    }

    return 0;
}