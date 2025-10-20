#include <iostream>
#include "CardList.h"

void CardList::addCards(const Cards& card){
    CardList.push_back(card);
}

bool CardList::removeCards(const std::string& n){
    for (auto it = CardList.begin(); it !=CardList.end(); ++it){
        if (it->getCardName() == n){
            CardList.erase(it);
            return true;
        }
    }
    return false;
}

void CardList::listCards() const{
    for(const auto& card : CardList){
        card.display();
    }
}

