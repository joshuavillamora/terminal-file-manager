#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::path currentPath = "/";

    for (const auto& entry : std::filesystem::directory_iterator(currentPath)) {
        std::cout << entry.path() << '\n';
    }

    return 0;
}