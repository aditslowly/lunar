#include <iostream>
#include <cstdlib>
#include "install.hpp"


void showBanner() {
std::cout << R"(
$$\       $$\   $$\ $$\   $$\  $$$$$$\  $$$$$$$\  
$$ |      $$ |  $$ |$$$\  $$ |$$  __$$\ $$  __$$\ 
$$ |      $$ |  $$ |$$$$\ $$ |$$ /  $$ |$$ |  $$ |
$$ |      $$ |  $$ |$$ $$\$$ |$$$$$$$$ |$$$$$$$  |
$$ |      $$ |  $$ |$$ \$$$$ |$$  __$$ |$$  __$$< 
$$ |      $$ |  $$ |$$ |\$$$ |$$ |  $$ |$$ |  $$ |
$$$$$$$$\ \$$$$$$  |$$ | \$$ |$$ |  $$ |$$ |  $$ |
\________| \______/ \__|  \__|\__|  \__|\__|  \__|
)" << std::endl;
}

void showMenu() {
    std::cout << "======================================" << std::endl;
    std::cout << "       Lunar Installation Menu: " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "1. Install Laragon App" << std::endl;
    std::cout << "2. Install NodeJS" << std::endl;
    std::cout << "3. Install Visual Studio Code" << std::endl;
    std::cout << "4. Install Python" << std::endl;
    std::cout << "5. Install All" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        #ifdef _WIN32
            system("cls"); // Clear screen for Windows
        #else
            system("clear"); // Clear screen for Linux/macOS
        #endif
        showBanner();
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                installLaragon();
                break;

            case 2:
                installNodeJS();
                break;

            case 3:
                installVisualStudioCode();
                break;

            case 4:
                installPython();
                break;

            case 5:
                installAll();
                break;

            case 6:
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }

        if (choice != 6) {
            std::cout << "\nPress Enter to return to the menu...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (choice != 6);

    return 0;
}
