#ifndef TRIPLEDRAFT_H
#define TRIPLEDRAFT_H

#include <vector>
#include <string>
#include "Cards.h"
#include "Deck.h"
#include "DeckGrader.h"


//TripleDraft class
class TripleDraft {
private:
    std::vector<Cards> allCards;
    std::vector<Cards> player1Deck;
    std::vector<Cards> player2Deck;

public:
    void loadCardsFromFile(const std::string& filename);
    void startDraft();
    void displayDecks();
    double gradeDeck(const std::vector<Cards>& deck, const std::string& playerName);
    void displayFinalResults(double player1Score, double player2Score);
    void saveCompleteResultsToFile(double player1Score, double player2Score);
};

#endif