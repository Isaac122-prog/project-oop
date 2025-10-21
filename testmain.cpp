#include <iostream>
#include <iomanip>
#include "Cards.h"
#include "Deck.h"
#include "DeckGrader.h"

int main() {
    // Create 8 cards (Trip_Role, Role, Rarity)
    Cards c1(5, 50, 40, 50, "Knight", "Tank", "MiniTank", "Common");
    Cards c2(4, 40, 50, 50, "Musketeer", "AntiAir", "AntiAir", "Rare");
    Cards c3(3, 0, 40, 40, "Fireball", "Spell", "BigSpell", "Rare");
    Cards c4(2, 10, 10, 20, "Ice Spirit", "CheapAA", "Distraction", "Common");
    Cards c5(6, 90, 80, 20, "Giant", "Tank", "WinCon", "Epic");
    Cards c6(3, 20, 30, 30, "Archer", "AntiAir", "CheapAntiAir", "Common");
    Cards c7(4, 40, 55, 60, "Wizard", "Splash", "AntiAir", "Epic");
    Cards c8(5, 50, 45, 0, "Baby Dragon", "Splash", "AntiAir", "Epic");

    // Create deck and add cards
    Deck myDeck;
    myDeck.addCard(c1);
    myDeck.addCard(c2);
    myDeck.addCard(c3);
    myDeck.addCard(c4);
    myDeck.addCard(c5);
    myDeck.addCard(c6);
    myDeck.addCard(c7);
    myDeck.addCard(c8);

    // Display deck
    std::cout << "\n--- Deck Contents ---\n";
    myDeck.displayDeck();

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
