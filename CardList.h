#ifndef CARDLIST_H
#define CARDLIST_H
#include "Cards.h"
#include <vector>

class CardList {
private:
    std::vector<Cards> cards;   // renamed from CardList
    
public:
    void addCards(const Cards& card);
    bool removeCards(const std::string& n);
    bool EditCards(std::string n, const Cards& update);
    void listCards() const;
    int getCardCount() const { return cards.size(); } // optional debug helper
    void exportToFile(const std::string& filename) const;
    bool findCardByName(const std::string& name, Cards& result) const;
    void loadFromFile(const std::string& filename);  // implement in cpp
    void displayCards() const;
};

#endif
