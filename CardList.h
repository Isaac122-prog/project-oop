#ifndef CARDLIST_H
#define CARDLIST_H
#include "Cards.h"

class CardList{
    private:
        std::vector<Cards> CardList;
    public:
        void addCards(const Cards& card);
        bool removeCards(const std::string& n);
        bool EditCards(std::string n, const Cards& update);
        void listCards() const;
};

#endif