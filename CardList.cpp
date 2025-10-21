#include <iostream>
#include "CardList.h"

void CardList::addCards(const Cards& card) {
    cards.push_back(card); // now refers unambiguously to the vector
}

bool CardList::removeCards(const std::string& n) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if (it->getCardName() == n) {
            cards.erase(it);
            return true;
        }
    }
    return false;
}

bool CardList::EditCards(std::string n, const Cards& update) {
    for (auto& card : cards) {
        if (card.getCardName() == n) {
            card = update;
            return true;
        }
    }
    return false;
}

void CardList::listCards() const {
    if (cards.empty()) {
        std::cout << "No cards in database.\n";
        return;
    }

    for (const auto& card : cards) {
        card.display();
        std::cout << "------------------------\n";
    }
}
