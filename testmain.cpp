#include <iostream>
#include <string>
#include <iomanip>
#include "Cards.h"
#include "CardList.h"
#include "Deck.h"
#include "DeckGrader.h"

int main() {
    CardList cardListClass;
    cardListClass.loadFromFile("cards.txt"); // or however you load your database

    std::cout << "\n==== Cards Database ====\n";
    cardListClass.displayCards();  // show all cards in the list

    Deck myDeck;
    std::string cardName;

    std::cout << "\nCreate your deck (pick 8 cards by name):\n";

    for (int i = 0; i < 8; ++i) {
        std::cout << "Enter card name #" << i + 1 << ": ";
        std::getline(std::cin, cardName);

        // Find card in the database
        Cards selectedCard;
        if (cardDatabase.findCardByName(cardName, selectedCard)) {
            myDeck.addCard(selectedCard);
            std::cout << cardName << " added to deck.\n";
        } else {
            std::cout << "Card not found. Try again.\n";
            --i; // retry this iteration
        }
    }

    std::cout << "\n--- Deck Contents ---\n";
    myDeck.displayDeck();

    // Grade the deck

    // Create DeckGrader
    DeckGrader grader;

    // Grade deck
    double avgElixir = grader.getAvgElixir(myDeck);
    double balanceScore = grader.gradeBalance(myDeck);
    double attackScore = grader.gradeAttack(myDeck);
    double defenseScore = grader.gradeDefense(myDeck);
    double totalScore = grader.gradeDeck(myDeck);
    double strengthScore = grader.gradeStrength(myDeck);

    std::cout << "\n--- Deck Grading ---\n";
    std::cout << "Average Elixir: " << avgElixir << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Balance Score: " << balanceScore << "\n";
    std::cout << "Attack Score: " << attackScore << "\n";
    std::cout << "Defense Score: " << defenseScore << "\n";
    std::cout << "Strength Score: " << strengthScore << "\n";
    std::cout << "Overall Deck Score: " << totalScore << "\n";

    if (totalScore < 50) {
        std::cout << "⭐️\n";
    } else if (totalScore >= 50 && totalScore < 100) {
        std::cout << "⭐️⭐️\n";
    } else if (totalScore >= 100 && totalScore < 150) {
        std::cout << "⭐️⭐️⭐️\n";
    } else if (totalScore >= 150 && totalScore < 200) {
        std::cout << "⭐️⭐️⭐️⭐️\n";
    } else {
        std::cout << "⭐️⭐️⭐️⭐️⭐️\n";
    }
    return 0;
}
