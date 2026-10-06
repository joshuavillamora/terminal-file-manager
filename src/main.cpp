#include <iostream>
#include <filesystem>
#include <vector>

int main() {
    std::filesystem::path currentPath = "/";
    std::vector<std::filesystem::path> directories;
    int choice;

    do {
        std::cout << currentPath << std::endl;

        int entryNumber = 1;
        
        for (const auto& entry : std::filesystem::directory_iterator(currentPath)) {
            std::cout << entryNumber << ". " << entry.path().filename().string();

            if (entry.is_directory()) {
                std::cout << "/";
                directories.push_back(entry.path().filename().string());
            }

            entryNumber++;
            std::cout << '\n';
        }

        std::cout << "\n";
        std::cout << ">> ";
        std::cin >> choice;

        if (choice > directories.size()) {
            std::cout << "Invalid input.\n";
        } else {
            currentPath /= directories[choice - 1];
        }

        directories.clear();

        if (choice == 0) {
            break;
        }
        
    } while (choice != 0);

    return 0;
}