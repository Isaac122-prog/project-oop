#include <iostream>
#include <fstream>
#include <sstream>
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

void CardList::exportToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cout << "Error: Could not open file for writing.\n";
        return;
    }

    outFile << "==== Cards Database ====\n";
    for (const auto& card : cards) { // assuming you have a std::vector<Cards> cards;
        outFile << "Name: " << card.getCardName()
                << ", Elixir: " << card.getCardElixir()
                << ", Attack: " << card.getCardAttack()
                << ", Defence: " << card.getCardDefence()
                << ", Health: " << card.getCardHealth()
                << ", TripleDraftRole: " << card.getCardTripleDraftRole()
                << ", Role: " << card.getCardRole()
                << ", Rarity: " << card.getCardRare()
                << "\n";
    }

    outFile.close();
    std::cout << "Card database successfully written to " << filename << "\n";
}

bool CardList::findCardByName(const std::string& name, Cards& result) const {
    for (const auto& card : cards) {
        if (card.getCardName() == name) {
            result = card;
            return true;
        }
    }
    return false;
}

void CardList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << "\n";
        return;
    }

    cards.clear(); 

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream is(line);

        int elixir, health, attack, defence;
        std::string name, tripleRole, role, rarity;

        // Adjust parsing depending on your file format
        if (is >> elixir >> health >> attack >> defence >> name >> tripleRole >> role >> rarity) {
            Cards card(elixir, health, attack, defence, name, tripleRole, role, rarity);
            addCards(card);
        }
    }

    file.close();
    std::cout << "Cards loaded from " << filename << "\n";
}

void CardList::displayCards() const {
    if (cards.empty()) {
        std::cout << "No cards in database.\n";
        return;
    }

    for (const auto& card : cards) {
        card.display(); // assumes Cards::display() is implemented
        std::cout << "------------------------\n";
    }
}