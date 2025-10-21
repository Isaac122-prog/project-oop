#include "Deck.h"
#include "Cards.h"

bool Deck::addCard(const Cards& card){
    if (deckList.size() >= 8) {
        std::cout << "Deck is full. Cannot add more cards.\n";
        return false;
    }
    deckList.push_back(card);
    std::cout << card.getCardName() << " added to deck.\n";
    return true;
}

bool Deck::removeCard(const std::string& name){
    for (auto it = deckList.begin(); it != deckList.end(); ++it) {
        if (it->getCardName() == name) {
            std::cout << name << " removed from deck.\n";
            deckList.erase(it);
            return true;
        }
    }
    std::cout << "Card not found: " << name << "\n";
    return false;
}
void Deck::displayDeck() const{
        if (deckList.empty()) {
        std::cout << "Deck is empty.\n";
        return;
    }

    std::cout << "Deck contains " << deckList.size() << " cards:\n";
    for (const auto& c : deckList) {
        c.display();
    }
}

int Deck::getCardCount() const{
    return static_cast<int>(deckList.size());
}

bool Deck::isFull() const{
    return deckList.size() >= 8;
}

const std::vector<Cards>& Deck::getCards() const {
    return deckList;
}