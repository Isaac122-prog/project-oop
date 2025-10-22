#ifndef DECK_H
#define DECK_H
#include <vector>
#include <iostream>
#include <string>
#include "Cards.h"

// Deck class
class Deck{

private:
    // stores all cards in the deck
    std::vector<Cards> deckList;

public:
    Deck();
    bool addCard(const Cards& card);
    bool removeCard(const std::string& name);
    void displayDeck() const;
    int getCardCount() const;
    bool isFull() const;
    const std::vector<Cards>& getCards() const;
};

#endif