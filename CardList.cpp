#include <iostream>
#include "CardList.h"

void CardList::addCards(const Cards& card){
    CardList.push_back(card);
}

bool CardList::removeCards(const std::string& name) {
    auto it = std::remove_if(CardList.begin(), CardList.end(),
        [&](const Cards& c) {
            return c.getNameConst() == name;
        });

    bool removed = (it != CardList.end());
    CardList.erase(it, CardList.end());
    return removed;
}

bool CardList::EditCards(std::string name, const Cards& update){
    for (const auto& card: CardList) {
        card.display();
        
    }
}

