#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "CardList.h"
#include "Cards.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void mainMenu(CardList& CardListClass){
    int choice;
    while (true) {
        clearScreen();
        while (true) {
            std::cout << "===== CLASH ROYAL ====\n";
            std::cout << "1. Cards Database\n";
            std::cout << "2. Manage Cards\n";
            std::cout << "3. Deck\n";
            std::cout << "4. Deck Grader\n";
            std::cout << "5. Tripple Draft\n";
            std::cout << "6. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                clearScreen();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter an integer.\n";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }
}