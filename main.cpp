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
            std::cout << "===== CLASH ROYALE ====\n";
            std::cout << "1. Cards Database\n";
            std::cout << "2. Manage Cards\n";
            std::cout << "3. Deck Grader\n";
            std::cout << "4. Tripple Draft\n";
            std::cout << "5. Exit\n";
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

            switch(choice) {
                case 1:
                clearScreen();
                std::cout << "==== Cards Database ====\n";
                CardListClass.listCards();
                pause();
                break;

                case 2:
                clearScreen();
                int CardChoice;
                while(true){
                    std::cout << "==== Card Database Menu ====\n";
                    std::cout << "1. Add Cards\n";
                    std::cout << "2. Delete Cards\n";
                    std::cout << "3. Edit Cards\n";
                    std::cout << "4. Back to main menu\n";

                    if (std::cin.fail()) { // exception handling to prevent errors
                    std::cin.clear();
                    clearScreen();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// discard bad input. This method for discarding bad inputs was discovered via ChatGPT and the prompt "How can I add exception handling for cin statements in C++?"
                    std::cout << "Invalid input. Please enter an integer.\n";
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                pause();
                break;
            }

            case 3:
            clearScreen();
            int DeckGrader;
            while (true){
                std::cout << "==== Deck Grader ====\n";
                std::cout << "1. make Deck\n";
                std::cout << "2. Back to main menu\n";
                std::cin >> DeckGrader;
            }

        }

    }
}

int main() {
    CardList cards;      // create your CardList object (make sure CardList has a default constructor)
    mainMenu(cards);     // call your main menu
    return 0;
}
