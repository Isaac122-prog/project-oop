#include "TripleDraft.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(0))); // randomiser

    std::cout << "--Triple Draft--\n";
    std::cout << "=== Welcome to Two-Player Triple Draft (8 cards each) ===\n\n";

    TripleDraft game;
    
    // Load cards from file
    game.loadCardsFromFile("Cards.txt");
    
    // Start the draft process
    game.startDraft();

    return 0;
}