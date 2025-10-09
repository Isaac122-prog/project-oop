#ifndef CARDLIST_H
#define CARDLIST_H
#include "Cards.h"

class CardList{
    private:
        std::vector<Cards> CardList;
    public:
        void addCards(const Cards& card);
        bool removeCards(const std::string& name);
        bool EditCards(std::string name, const Cards& update);
};

#endif