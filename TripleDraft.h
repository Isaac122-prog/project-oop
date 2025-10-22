#ifndef TRIPLEDRAFT_H
#define TRIPLEDRAFT_H

#include <vector>
#include <string>

struct Card {
    std::string name;
    int elixir;
    int health;
    int attack;
    int defense;
    std::string rarity;
    std::string role;
    std::string emoji;
};

// Load all cards from a column-separated file
std::vector<Card> loadCardsFromFile(const std::string& filename);

// Select n random cards from all available cards
std::vector<Card> selectRandomCards(std::vector<Card>& allCards, int n);

// Let a player draft 8 cards from available cards
std::vector<Card> playerDraft(std::vector<Card>& availableCards, const std::string& playerName);

// Save drafted decks to file
void saveDeckToFile(const std::string& filename, const std::vector<Card>& deck, const std::string& playerName);

#endif // TRIPLEDRAFT_H
