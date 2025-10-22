#include "Deck.h"
#include "Cards.h"

// adds card to deck, if deck full, return false
bool Deck::addCard(const Cards& card){
    if (deckList.size() >= 8) { // check if deck is full
        std::cout << "Deck is full. Cannot add more cards.\n";
        return false;
    }
    std::cout << std::endl;
    deckList.push_back(card); // add card to deck
    std::cout << card.getCardName() << " added to deck.\n";
    return true;
}

// removes card by name
bool Deck::removeCard(const std::string& name){
    for (auto it = deckList.begin(); it != deckList.end(); ++it) {
        if (it->getCardName() == name) { // check if card name matches
            std::cout << name << " removed from deck.\n";
            deckList.erase(it); // removes card
            return true;
        }
    }
    std::cout << "Card not found: " << name << "\n";
    return false;
}

// displays all cards in deck
void Deck::displayDeck() const{
        if (deckList.empty()) { // if empty
        std::cout << "Deck is empty.\n";
        return;
    }

    std::cout << "Deck contains " << deckList.size() << " cards:\n";
    for (const auto& c : deckList) { // diplays each card
        c.display(); 
    }
}

// returns number of cards in deck
int Deck::getCardCount() const{
    return static_cast<int>(deckList.size());
}

// check if deck is full
bool Deck::isFull() const{
    return deckList.size() >= 8;
}

// returns a constant reference to vector of cards
const std::vector<Cards>& Deck::getCards() const {
    return deckList;
}

// default constructor
Deck::Deck() {}