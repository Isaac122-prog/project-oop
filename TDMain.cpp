#include "TripleDraft.h"
#include <iostream>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Load all cards from text file
    std::vector<Card> allCards = loadCardsFromFile("cards.txt");

    if (allCards.empty()) {
        std::cerr << "No cards loaded. Check your cards.txt file.\n";
        return 1;
    }

    // Randomly select 30 cards for this draft
    std::vector<Card> availableCards = selectRandomCards(allCards, 30);

    std::cout << "\n=== Welcome to Two-Player Triple Draft (8 cards each) ===\n";

    // Player 1 drafts 8 cards
    std::vector<Card> player1Deck = playerDraft(availableCards, "Player 1");

    // Player 2 drafts 8 cards
    std::vector<Card> player2Deck = playerDraft(availableCards, "Player 2");

    // Display drafted decks
    std::cout << "\n=== Player 1 Deck ===\n";
    for (const auto& c : player1Deck)
        std::cout << c.name << " (" << c.elixir << " elixir, "
                  << c.attack << " ATK, "
                  << c.defense << " DEF, "
                  << c.rarity << " " << c.emoji
                  << ", " << c.role << ")\n";

    std::cout << "\n=== Player 2 Deck ===\n";
    for (const auto& c : player2Deck)
        std::cout << c.name << " (" << c.elixir << " elixir, "
                  << c.attack << " ATK, "
                  << c.defense << " DEF, "
                  << c.rarity << " " << c.emoji
                  << ", " << c.role << ")\n";

    // Save results to file
    saveDeckToFile("draft_results.txt", player1Deck, "Player 1");
    saveDeckToFile("draft_results.txt", player2Deck, "Player 2");

    std::cout << "\nDraft complete! Results saved to draft_results.txt\n";
    return 0;
}
