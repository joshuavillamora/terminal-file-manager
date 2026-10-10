#include <iostream>
#include <filesystem>
#include <vector>

int main() {
    std::filesystem::path currentPath = "/";
    std::vector<std::filesystem::directory_entry> entries;
    int choice;

    do {
        int entryNumber = 1;
        
        for (const auto& entry : std::filesystem::directory_iterator(currentPath)) {
            std::cout << entryNumber << ". " << entry.path().filename().string();
            entries.push_back(entry);

            if (entry.is_directory()) {
                std::cout << "/";
            }

            entryNumber++;
            std::cout << '\n';
        }

        std::cout << entryNumber << ". Exit\n";

        std::cout << "\n";
        std::cout << ">> ";
        std::cin >> choice;

        if (choice == entryNumber) {
            currentPath = currentPath.parent_path();
        } else if (choice > entries.size()) {
            std::cout << "Invalid input.\n";
        } else {
            if (entries[choice - 1].is_directory()) {
                currentPath /= entries[choice - 1];
            } else {
                std::cout << "Cannot enter a file.\n";
            }
        }

        entries.clear();

        if (choice == 0) {
            break;
        }
        
    } while (choice != 0);

    return 0;
}