#ifndef DECKGRADER_H
#define DECKGRADER_H
#include <unordered_map>
#include <string>
#include "Deck.h"

// Deckgrading class
class DeckGrader{
    private:
        // Maps each card role to a map of card count → score for grading decks
        std::unordered_map<std::string, std::unordered_map<int, int>> roleScores;
    public:
        DeckGrader();
        double gradeDeck(const Deck& deck);
        double gradeAttack(const Deck& deck);
        double gradeDefense(const Deck& deck);
        double gradeStrength(const Deck& deck);
        double gradeBalance(const Deck& deck);
        double getAvgElixir(const Deck& deck);
};

#endif