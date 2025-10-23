#include <iostream>
#include <fstream> // file writing and reading
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include "CardList.h"
#include "Cards.h"
#include "TripleDraft.h"
#include "DeckGrader.h"
#include "Deck.h"

// Function to clear the console screen got (from internet)
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Clear screen on Windows
#else
    system("clear");  // Clear screen on Linux/macOS
#endif
}
// Function to pause execution until user presses Enter
void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Main menu function
void mainMenu(CardList& CardListClass) {
    int choice;
    while (true) {
        clearScreen();
        while (true) { // Input validation loop
            std::cout << "===== CLASH ROYALE ====\n";
            std::cout << "1. Cards Database\n";
            std::cout << "2. Manage Cards\n";
            std::cout << "3. Deck Grader\n";
            std::cout << "4. Triple Draft\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            //Error Testing: input Validation
            if (std::cin.fail()) { // If input is not an integer
                std::cin.clear();
                clearScreen();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter an integer.\n";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; // valid input, exit validation loop
            }
        }

        switch (choice) {
            // case 1: card database
            case 1:
                clearScreen();
                std::cout << "==== Cards Database ====\n";
                CardListClass.listCards(); // prints and displays the card list
                pause();
                break;

            // ===== Case 2 =====
            case 2: {
                int CardChoice;
                while (true) {  // Card Database Menu loop
                    clearScreen();
                    std::cout << "==== Card Database Menu ====\n";
                    std::cout << "1. Add Cards\n";
                    std::cout << "2. Delete Cards\n";
                    std::cout << "3. Insert file\n";
                    std::cout << "4. Print Card Database\n";
                    std::cout << "5. Back to main menu\n";
                    
                    // Error Handling: first part of try catching
                    try { // whats in the try bracket has the chance to fail
                        std::cout << "Enter choice: ";
                        std::cin >> CardChoice;

                        if (std::cin.fail()) { //if there is an error
                            throw std::runtime_error("Invalid input. Please enter an integer."); // there is then a throw which is exception which stops the execution
                        }
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        if (CardChoice == 5) 
                        break; // back to main menu

                        if (CardChoice == 1) {
                            // ===== Add Card =====
                            int He, Att, Def, Elix;
                            std::string n, rare, r, T_Role;
                            std::string RoleRaw, RareRaw, T_RoleRaw;

                            // Name
                            clearScreen();
                            std::cout << "Enter name: ";
                            std::getline(std::cin, n);

                            // Attack
                            while (true) {
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

                            // Defence
                            while (true) {
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
                            while (true) {
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
                            while (true) {
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

                            // Triple Draft Role
                            while (true) {
                                std::cout << "Enter Triple Draft Role: ";
                                std::getline(std::cin, T_RoleRaw);
                                if (T_RoleRaw == "WinCon" || T_RoleRaw == "SmallSpell" || T_RoleRaw == "BigSpell" ||
                                    T_RoleRaw == "AntiAir" || T_RoleRaw == "CheapAntiAir" || T_RoleRaw == "TankSupport" ||
                                    T_RoleRaw == "AntiTank" || T_RoleRaw == "MiniTank" || T_RoleRaw == "Distraction") {
                                    T_Role = T_RoleRaw;
                                    break;
                                } else {
                                    std::cout << "Invalid input. Options: WinCon, SmallSpell, BigSpell, AntiAir, "
                                            << "CheapAntiAir, TankSupport, AntiTank, MiniTank, Distraction\n";
                                }
                            }

                            // Role
                            while (true) {
                                std::cout << "Enter Role: ";
                                std::getline(std::cin, RoleRaw);
                                if (RoleRaw == "WinCon" || RoleRaw == "SmallSpell" || RoleRaw == "BigSpell" ||
                                    RoleRaw == "AntiAir" || RoleRaw == "CheapAntiAir" || RoleRaw == "HeavyTank" ||
                                    RoleRaw == "MiniTank" || RoleRaw == "Building" || RoleRaw == "Distraction") {
                                    r = RoleRaw;
                                    break;
                                } else {
                                    std::cout << "Invalid input. Options: WinCon, SmallSpell, BigSpell, AntiAir, "
                                            << "CheapAntiAir, TankSupport, AntiTank, MiniTank, Distraction\n";
                                }
                            }

                            // Rarity
                            while (true) {
                                std::cout << "Enter Rarity: ";
                                std::getline(std::cin, RareRaw);
                                if (RareRaw == "Common" || RareRaw == "Rare" || RareRaw == "Epic" || RareRaw == "Legendary") {
                                    rare = RareRaw;
                                    break;
                                } else {
                                    std::cout << "Invalid input. Options: Common, Rare, Epic, Legendary\n";
                                }
                            }

                            //creates a new card object and adds to database
                            Cards newCard(Elix, He, Att, Def, n, T_Role, r, rare);
                            CardListClass.addCards(newCard);
                            std::cout << "Card added.\n";
                            pause();
                        }

                        //goes to delete card menu
                        else if (CardChoice == 2) {
                            std::string n;
                            std::cout << "Enter the name of the card to remove: ";
                            std::getline(std::cin, n);
                            if (CardListClass.removeCards(n))
                                std::cout << "Card removed.\n";
                            else
                                std::cout << "Card not found.\n";
                            pause();
                        }

                        else if (CardChoice == 3) { // Insert file
                            std::string filename;
                            std::cout << "Enter file name (e.g. cards.txt): ";
                            std::getline(std::cin, filename);
                            CardListClass.loadFromFile(filename);
                            pause();
                        }

                        else if (CardChoice == 4) { // Print file
                            std::string filename;
                            std::cout << "Enter file name to save (e.g. cards_output.txt): ";
                            std::getline(std::cin, filename);
                            CardListClass.exportToFile(filename);
                            pause();
                        }

                        else { // Invalid choice
                            throw std::runtime_error("Invalid choice. Select 1-5.");
                        }
                    }
                    catch (const std::exception& e) { // this catches the thrown exeception, "e" is the contains the error message
                        std::cin.clear(); 
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input buffer so isn't stuck 
                        std::cout << "Error: " << e.what() << "\n"; //prints the "e" message
                        pause();
                    }
                } // end of Card Database Menu loop
                break;
            }

            // ===== Case 3 =====
            case 3: {
                clearScreen();
                std::cout << "==== Deck Grader ====\n";

                CardList cardList;
                cardList.loadFromFile("cards.txt"); // implemented in CardList.cpp

                std::cout << "\n==== Cards Database ====\n";
                cardList.displayCards();

                Deck myDeck;
                std::string cardName;

                std::cout << "\nCreate your deck (pick 8 cards by name):\n";

                for (int i = 0; i < 8; ++i) {
                    std::cout << "Enter card name #" << i + 1 << ": ";
                    std::getline(std::cin, cardName);

                    Cards selectedCard(0, 0, 0, 0, "", "", "", "");
                    if (cardList.findCardByName(cardName, selectedCard)) {
                        myDeck.addCard(selectedCard);
                    } else {
                        std::cout << "Card not found. Try again.\n";
                        --i;
                    }
                }


                std::cout << "\n--- Deck Contents ---\n";
                myDeck.displayDeck();
                
                // create deckgrader object to grade deck
                DeckGrader grader;
                std::cout << std::fixed << std::setprecision(1);
                std::cout << "\n--- Deck Grading ---\n";

                // prints metrics of deck through grading class
                std::cout << "Average Elixir: " << grader.getAvgElixir(myDeck) << "\n";
                std::cout << "Balance Score: " << grader.gradeBalance(myDeck) << "\n";
                std::cout << "Attack Score: " << grader.gradeAttack(myDeck) << "\n";
                std::cout << "Defense Score: " << grader.gradeDefense(myDeck) << "\n";
                std::cout << "Strength Score: " << grader.gradeStrength(myDeck) << "\n";
                double totalScore = grader.gradeDeck(myDeck);
                std::cout << "Overall Deck Score: " << totalScore << "\n";

                // display visual rating for overall score
                if (totalScore < 150)
                    std::cout << "⭐️\n";
                else if (totalScore < 175)
                    std::cout << "⭐️⭐️\n";
                else if (totalScore < 200)
                    std::cout << "⭐️⭐️⭐️\n";
                else if (totalScore < 225)
                    std::cout << "⭐️⭐️⭐️⭐️\n";
                else
                    std::cout << "⭐️⭐️⭐️⭐️⭐️\n";

                pause();
                break;
            }

            // case 4
            case 4: {
                    srand(static_cast<unsigned int>(time(0))); // randomiser

                    std::cout << std::endl;

                    TripleDraft game;
    
                    // Load cards from file
                    game.loadCardsFromFile("cards.txt");
    
                    // Start the draft process
                    game.startDraft();

                    pause();
                    break;
            }

            // ===== Exit =====
            case 5:
                std::cout << "Exiting...\n";
                return;

            default:
                std::cout << "Invalid choice.\n";
                pause();
            }
    }
}

int main() {
    CardList cards; // Create a CardList object to hold all cards in the database
    mainMenu(cards);
    /// Call the main menu function and pass the CardList object
    // User can interact with cards database, manage cards, grade decks, or play triple draft
    return 0;
}
