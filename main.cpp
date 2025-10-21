#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include "CardList.h"
#include "Cards.h"
#include "TripleDraft.h"

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
            std::cout << "4. Triple Draft\n";
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
            int CardChoice;
            while(true){
                clearScreen();
                std::cout << "==== Card Database Menu ====\n";
                std::cout << "1. Add Cards\n";
                std::cout << "2. Delete Cards\n";
                std::cout << "3. Insert file\n";
                std::cout << "4. Back to main menu\n";
                std::cout << "Enter choice: ";
                std::cin >> CardChoice;

                if (std::cin.fail()) { // exception handling to prevent errors
                    std::cin.clear();
                    clearScreen();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// discard bad input. This method for discarding bad inputs was discovered via ChatGPT and the prompt "How can I add exception handling for cin statements in C++?"
                    std::cout << "Invalid input. Please enter an integer.\n";
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }
                if(CardChoice == 1){
                    int He;
                    int Att;
                    int Def;
                    int Elix;
                    std::string n;
                    std::string rare;
                    std::string RareRaw;
                    std::string r;
                    std::string RoleRaw;
                    std::string T_Role;
                    std::string T_RoleRaw;

                    clearScreen();

                    //Name
                    std::cout << "Enter name: ";
                    std::getline(std::cin, n);
                
                    // Attack
                    while(true){
                        std::cout << "Enter Attack: ";
                        std::cin >> Att;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a number.\n";
                        } else {
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                    }

                    //Defence
                    while(true){
                        std::cout << "Enter Defence: ";
                        std::cin >> Def;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a number.\n";
                        } else {
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                    }
                    
                    // Health
                    while(true){
                        std::cout << "Enter Health: ";
                        std::cin >> He;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a number.\n";
                        } else {
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                    }

                    // Elixir
                    while(true){
                        std::cout << "Enter Elixir: ";
                        std::cin >> Elix;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a number.\n";
                        } else {
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                    }

                    while (true){
                        std::cout << "Enter Triple Draft Role: ";
                        std::getline(std::cin, T_RoleRaw);
                        if(T_RoleRaw == "WinCon" || T_RoleRaw == "SmallSpell" || T_RoleRaw == "BigSpell" || T_RoleRaw == "AntiAir" || T_RoleRaw == "CheapAntiAir" || T_RoleRaw == "tankSupport" 
                        || T_RoleRaw == "AntiTank" || T_RoleRaw == "MiniTank" || T_RoleRaw == "Distraction"){
                            T_Role = T_RoleRaw;
                            break;
                        }
                        else{
                            std::cout << "invalid input. Please enter one the options\n";
                            std::cout << "WinCon, SmallSpell, BigSpell, AntiAir, CheapAntiAir, TankSupport, AntiTank, MiniTank, Distraction\n";
                        }
                    }

                    // Role
                    while(true){
                        std::cout << "Enter Role: ";
                        std::getline(std::cin, RoleRaw);
                        if(RoleRaw == "WinCon" || RoleRaw == "SmallSpell" || RoleRaw == "BigSpell" || RoleRaw == "AntiAir" || RoleRaw == "CheapAntiAir" || RoleRaw == "HeavyTank"
                        || RoleRaw == "MiniTank" || RoleRaw == "Building" || RoleRaw == "Distraction"){
                            r = RoleRaw;
                            break;
                        }
                        else{
                            std::cout << "invalid input. Please enter one the options\n";
                        }
                    }

                    //Rarity
                  while(true){
                        std::cout << "Enter Rarity: ";
                        std::getline(std::cin, RareRaw);
                        if(RareRaw == "Common" || RareRaw == "Rare" || RareRaw == "Epic" || RareRaw == "Legendary"){
                            rare = RareRaw;
                            break;
                        }
                        else{
                            std::cout << "invalid input. Please enter one the options\n";
                        }
                    }
                    Cards newCard(Elix, He, Att, Def, n, T_Role, r, rare);
                    CardListClass.addCards(newCard);
                    std::cout << "Card added.\n";
                }
                    else if (CardChoice == 2) {
                        std::string n;
                        std::cout << "Enter the name of the card to remove: ";
                        std::cin >> n;
                        std::cin.ignore();
                    if (CardListClass.removeCards(n)) {
                        std::cout << "Employee removed.\n";
                    } else {
                        std::cout << "Employee not found.\n";
                    }
                }
                    // import a text file so that the card can be auto inputted
                    else if(CardChoice == 3){
                        std::string filename;
                        std::cout << "Enter file name (e.g. cards.txt): ";
                        std::getline(std::cin, filename);

                        std::ifstream file(filename);
                    if (!file.is_open()) {
                        std::cout << "Error: Could not open file.\n";
                    } else {
                        int He;
                        int Att;
                        int Def;
                        int Elix;
                        std::string n;
                        std::string rare;
                        std::string r;
                        std::string T_Role;

                        int count = 0;
                        while (file >> Elix >> He >> Att >> Def >> n >> T_Role >>r >> rare) {
                            Cards newCard(Elix, He, Att, Def, n, T_Role, r, rare);
                            CardListClass.addCards(newCard);
                            count++;
                            std::cout << "Imported: " << n << "\n";
                        }

                        file.close();
                        std::cout << count << " cards imported successfully from " << filename << ".\n";
                    }
                    pause();
                }
            }
        }
}



int main() {
    CardList cards;      // create your CardList object (make sure CardList has a default constructor)
    mainMenu(cards);     // call your main menu
    return 0;
}
