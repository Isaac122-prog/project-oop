#include "TripleDraft.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
#include <iomanip>

//loads data from the file
void TripleDraft::loadCardsFromFile(const std::string& filename) {
    allCards.clear();
    std::ifstream file(filename);
    if (!file) { std::cerr << "Cannot open " << filename << "\n"; return; }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream is(line);
        int el, hp, atk, def;
        std::string name, role, tRole, rarity;
        is >> el >> hp >> atk >> def >> name >> role >> tRole >> rarity;
        allCards.emplace_back(el, hp, atk, def, name, tRole, role, rarity);
    }
}

void TripleDraft::startDraft() {
    std::cout << "--Triple Draft--\n";
    std::cout << "=== Welcome to Two-Player Triple Draft (8 cards each) ===\n\n";

    // randomiser to choose cards randomly
    std::random_device rd;
    std::mt19937 g(rd());
    
    //does the drafing for players
    auto draftPlayer = [this, &g](std::vector<Cards>& deck, const std::string& playerName) {
        std::vector<Cards> pool = allCards;
        for (int i = 0; i < 8; ++i) {
            std::shuffle(pool.begin(), pool.end(), g);

            std::cout << "=== " << playerName << " Draft " << i+1 << " of 8 ===\n";

            // shows 3 card options for players
            for (int j = 0; j < 3 && j < static_cast<int>(pool.size()); ++j) {
                const auto& card = pool[j];
                std::cout << j+1 << ": " << card.getCardName() 
                          << " (" << card.getCardElixir() << " Elixir, "
                          << card.getCardHealth() << " Health, "
                          << card.getCardAttack() << " Attack, "
                          << card.getCardDefence() << " Defence, "
                          << card.getCardRare() << " "
                          << card.getCardTripleDraftRole() << ", "
                          << card.getCardRole() << ")\n";
            }

            //validation checker
            int choice;
            while (true) {
                std::cout << "Enter your choice (1-3): ";
                if (std::cin >> choice && choice >= 1 && choice <= 3) break;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Invalid choice.\n";
            }
            //adds card and removes it from the list
            deck.push_back(pool[choice-1]);
            pool.erase(pool.begin() + choice-1);
            std::cout << "\n";
        }
    };

    //starts player drafts
    draftPlayer(player1Deck, "Player 1");
    draftPlayer(player2Deck, "Player 2");

    // Display final decks
    displayDecks();
    
    // Grade decks and get scores
    double player1Score = gradeDeck(player1Deck, "Player 1");
    double player2Score = gradeDeck(player2Deck, "Player 2");

    // Display final results and determine winner
    displayFinalResults(player1Score, player2Score);
    
    // Save complete results to file
    saveCompleteResultsToFile(player1Score, player2Score);
}

// display each deck
void TripleDraft::displayDecks() {
    std::cout << "=== Player 1 Deck ===\n";
    for (const auto& card : player1Deck) {
        std::cout << card.getCardName() << " (" << card.getCardElixir() << " elixir, "
                  << card.getCardAttack() << " ATK, " << card.getCardDefence() << " DEF, "
                  << card.getCardRare() << " " << card.getCardTripleDraftRole() << ", "
                  << card.getCardRole() << ")\n";
    }
    std::cout << "\n";

    std::cout << "=== Player 2 Deck ===\n";
    for (const auto& card : player2Deck) {
        std::cout << card.getCardName() << " (" << card.getCardElixir() << " elixir, "
                  << card.getCardAttack() << " ATK, " << card.getCardDefence() << " DEF, "
                  << card.getCardRare() << " " << card.getCardTripleDraftRole() << ", "
                  << card.getCardRole() << ")\n";
    }
    std::cout << "\n\n";
}

// grades each players deck
double TripleDraft::gradeDeck(const std::vector<Cards>& deck, const std::string& playerName) {
    Deck graderDeck;
    for (const auto& c : deck)
        graderDeck.addCard(c);

    DeckGrader grader;
    double totalScore = grader.gradeDeck(graderDeck);
    double avgElixir = grader.getAvgElixir(graderDeck);
    double balanceScore = grader.gradeBalance(graderDeck);
    double attackScore = grader.gradeAttack(graderDeck);
    double defenseScore = grader.gradeDefense(graderDeck);
    double strengthScore = grader.gradeStrength(graderDeck);

    std::cout << "--- " << playerName << " Deck Grading ---\n";
    std::cout << "Average Elixir: " << std::fixed << std::setprecision(1) << avgElixir << "\n";
    std::cout << "Balance Score: " << std::fixed << std::setprecision(1) << balanceScore << "\n";
    std::cout << "Attack Score: " << std::fixed << std::setprecision(1) << attackScore << "\n";
    std::cout << "Defense Score: " << std::fixed << std::setprecision(1) << defenseScore << "\n";
    std::cout << "Strength Score: " << std::fixed << std::setprecision(1) << strengthScore << "\n";
    std::cout << "Overall Deck Score: " << std::fixed << std::setprecision(1) << totalScore << "\n";
    
    // Star rating
    if (totalScore < 150) std::cout << "⭐️\n";
    else if (totalScore < 175) std::cout << "⭐️⭐️\n";
    else if (totalScore < 200) std::cout << "⭐️⭐️⭐️\n";
    else if (totalScore < 225) std::cout << "⭐️⭐️⭐️⭐️\n";
    else std::cout << "⭐️⭐️⭐️⭐️⭐️\n";
    
    std::cout << "\n";

    return totalScore;
}

// displays who wins overall
void TripleDraft::displayFinalResults(double player1Score, double player2Score) {
    std::cout << "\n--- Player 1 Overall Deck Score: " << std::fixed << std::setprecision(1) << player1Score << " ---\n";
    std::cout << "--- Player 2 Overall Deck Score: " << std::fixed << std::setprecision(1) << player2Score << " ---\n\n";

    // Determine winner
    if (player1Score > player2Score) {
        std::cout << "Player 1 wins!\n";
    }
    else if (player2Score > player1Score) {
        std::cout << "Player 2 wins!\n";
    }
    else {
        std::cout << "It's a tie!\n";
    }

    std::cout << "\nDraft complete! Results saved to draft_results.txt\n";
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

// saves into a file
void TripleDraft::saveCompleteResultsToFile(double player1Score, double player2Score) {
    std::ofstream file("draft_results.txt");
    if (file) {
        file << "========================================\n";
        file << "          TRIPLE DRAFT RESULTS          \n";
        file << "========================================\n\n";
        
        // Player 1 deck
        file << "PLAYER 1 DECK:\n";
        file << "-------------\n";
        for (const auto& card : player1Deck) {
            file << "• " << card.getCardName() 
                 << " (" << card.getCardElixir() << " elixir, "
                 << card.getCardAttack() << " ATK, " << card.getCardDefence() << " DEF, "
                 << card.getCardRare() << " " << card.getCardTripleDraftRole() << ", "
                 << card.getCardRole() << ")\n";
        }
        file << "Player 1 Score: " << std::fixed << std::setprecision(1) << player1Score << "\n\n";
        
        // Player 2 deck  
        file << "PLAYER 2 DECK:\n";
        file << "-------------\n";
        for (const auto& card : player2Deck) {
            file << "• " << card.getCardName() 
                 << " (" << card.getCardElixir() << " elixir, "
                 << card.getCardAttack() << " ATK, " << card.getCardDefence() << " DEF, "
                 << card.getCardRare() << " " << card.getCardTripleDraftRole() << ", "
                 << card.getCardRole() << ")\n";
        }
        file << "Player 2 Score: " << std::fixed << std::setprecision(1) << player2Score << "\n\n";
        
        file << "========================================\n";
        file << "               FINAL RESULT             \n";
        file << "========================================\n";
        
        // Determine and write winner
        if (player1Score > player2Score) {
            file << " WINNER: PLAYER 1 \n";
            file << "Player 1 wins with " << player1Score << " points vs Player 2's " << player2Score << " points\n";
        }
        else if (player2Score > player1Score) {
            file << " WINNER: PLAYER 2 \n";
            file << "Player 2 wins with " << player2Score << " points vs Player 1's " << player1Score << " points\n";
        }
        else {
            file << " RESULT: TIE \n";
            file << "Both players scored " << player1Score << " points\n";
        }
        
        file << "========================================\n";
        file << "\nGame completed on: " << __DATE__ << " at " << __TIME__ << "\n";
        
        file.close();
        std::cout << " Complete results saved to draft_results.txt\n";
    } else {
        std::cerr << " Error: Could not save results to file!\n";
    }
}