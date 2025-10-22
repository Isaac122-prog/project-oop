#ifndef CARDLIST_H
#define CARDLIST_H
#include "Cards.h"
#include <vector>

class CardList {
private:
    std::vector<Cards> cards; // Include vector to store a dynamic list of Cards
public:
    // Add a new card to the database
    void addCards(const Cards& card);

    // Remove a card by name
    bool removeCards(const std::string& n);

    // List all cards in the database (prints to console)
    void listCards() const;

    // Get the total number of cards in the database
    int getCardCount() const { return cards.size(); }

    // Export all cards to a file (used in printing database to txt)
    void exportToFile(const std::string& filename) const;

    // Search for a card by name
    bool findCardByName(const std::string& name, Cards& result) const;

    // Load cards from a file into the database
    void loadFromFile(const std::string& filename);

    // Display all cards
    void displayCards() const;
};

#endif
