#include "TripleDraft.h"
#include "Deck.h"
#include "DeckGrader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <random>

// ===== Load cards from file =====
std::vector<Card> loadCardsFromFile(const std::string& filename) {
    std::vector<Card> cards;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return cards;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        Card c;

        iss >> c.elixir >> c.attack >> c.defense;
        iss >> std::ws;

        // Extract remaining parts
        std::string word;
        std::vector<std::string> parts;
        while (iss >> word) parts.push_back(word);

        if (parts.size() < 4) continue;

        // Last 3 tokens are metadata
        c.rarity = parts.back(); parts.pop_back();
        c.emoji = parts.back(); parts.pop_back();
        c.role = parts.back(); parts.pop_back();

        // The rest is the name
        c.name.clear();
        for (size_t i = 0; i < parts.size(); ++i) {
            c.name += parts[i];
            if (i < parts.size() - 1) c.name += " ";
        }

        cards.push_back(c);
    }

    return cards;
}

// ===== Random selection =====
std::vector<Card> selectRandomCards(std::vector<Card>& allCards, int n) {
    std::vector<Card> selected = allCards;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(selected.begin(), selected.end(), g);

    if (n < static_cast<int>(selected.size()))
        selected.resize(n);

    return selected;
}

// ===== Helper for name formatting =====
std::string formatName(const std::string& name, int width = 15) {
    if (name.size() > width - 2)
        return name.substr(0, width - 2) + ".";
    return name;
}

// ===== Player Draft =====
std::vector<Card> playerDraft(std::vector<Card>& availableCards, const std::string& playerName) {
    std::vector<Card> playerDeck;
    std::random_device rd;
    std::mt19937 g(rd());

    for (int draft = 1; draft <= 8; draft++) {
        std::cout << "\n=== " << playerName << " Draft " << draft << " of 8 ===\n";

        // Pick 3 random unique options
        std::vector<int> indices;
        while (indices.size() < 3 && !availableCards.empty()) {
            int randIndex = std::uniform_int_distribution<int>(0, availableCards.size() - 1)(g);
            if (std::find(indices.begin(), indices.end(), randIndex) == indices.end())
                indices.push_back(randIndex);
        }

        // Display options
        for (int i = 0; i < 3 && i < static_cast<int>(indices.size()); i++) {
            Card &c = availableCards[indices[i]];
            std::cout << i + 1 << ": " << c.name 
                      << " (" << c.elixir << " elixir, "
                      << c.attack << " ATK, "
                      << c.defense << " DEF, "
                      << c.rarity << " " << c.emoji
                      << ", " << c.role << ")\n";
        }

        // Player chooses
        int choice;
        while (true) {
            std::cout << "Enter your choice (1-3): ";
            if (std::cin >> choice && choice >= 1 && choice <= 3) break;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid choice. Try again.\n";
        }

        int chosenIndex = indices[choice - 1];
        playerDeck.push_back(availableCards[chosenIndex]);

        // Remove chosen card
        availableCards.erase(availableCards.begin() + chosenIndex);
    }

    return playerDeck;
}

// ===== Save Deck to File =====
void saveDeckToFile(const std::string& filename, const std::vector<Card>& deck, const std::string& playerName) {
    std::ofstream out(filename, std::ios::app);
    if (!out) return;
    out << "\n=== " << playerName << " Deck ===\n";
    for (const auto& c : deck)
        out << c.name << " (" << c.elixir << " elixir, " 
            << c.attack << " ATK, " << c.defense << " DEF, " 
            << c.rarity << " " << c.emoji << ", " << c.role << ")\n";
}

// ===== NEW: Grade and Determine Winner =====
void gradeAndDetermineWinner(const std::vector<Card>& deck1, const std::vector<Card>& deck2,
                             const std::string& player1, const std::string& player2) {
    Deck d1, d2;
    for (const auto& c : deck1)
        d1.addCard(Cards(c.elixir, 0, c.attack, c.defense, c.name, c.role, c.emoji, c.rarity));

    for (const auto& c : deck2)
        d2.addCard(Cards(c.elixir, 0, c.attack, c.defense, c.name, c.role, c.emoji, c.rarity));

    DeckGrader grader;

    double score1 = grader.gradeDeck(d1);
    double score2 = grader.gradeDeck(d2);

    std::cout << "\n--- Deck Scores ---\n";
    std::cout << player1 << ": " << std::fixed << std::setprecision(2) << score1 << "\n";
    std::cout << player2 << ": " << std::fixed << std::setprecision(2) << score2 << "\n";

    if (score1 > score2)
        std::cout << "\n🏆 " << player1 << " wins the Triple Draft!\n";
    else if (score2 > score1)
        std::cout << "\n🏆 " << player2 << " wins the Triple Draft!\n";
    else
        std::cout << "\n🤝 It's a tie!\n";
}

// ===== MAIN Triple Draft Flow =====
void runTripleDraftGame() {
    std::vector<Card> allCards = loadCardsFromFile("cards.txt");
    if (allCards.empty()) return;

    std::cout << "Welcome to Triple Draft Mode!\n";
    std::cout << "Player 1, enter your name: ";
    std::string player1;
    std::cin >> player1;
    std::cout << "Player 2, enter your name: ";
    std::string player2;
    std::cin >> player2;

    // Each player drafts
    std::vector<Card> cardsForPlayer1 = selectRandomCards(allCards, 24);
    std::vector<Card> player1Deck = playerDraft(cardsForPlayer1, player1);

    std::vector<Card> cardsForPlayer2 = selectRandomCards(allCards, 24);
    std::vector<Card> player2Deck = playerDraft(cardsForPlayer2, player2);

    // Save decks
    saveDeckToFile("decks_output.txt", player1Deck, player1);
    saveDeckToFile("decks_output.txt", player2Deck, player2);

    // Grade both decks
    gradeAndDetermineWinner(player1Deck, player2Deck, player1, player2);
}
