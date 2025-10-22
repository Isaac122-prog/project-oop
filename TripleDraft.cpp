#include "TripleDraft.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include "DeckGrader.h"
#include "Deck.h"
#include <iomanip>
#include <random>

// Load cards from your space separated file
std::vector<Card> loadCardsFromFile(const std::string& filename) {
    std::vector<Card> cards;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return cards;
    }

//reads through line by line
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream is(line);
        Card c;
// puts in in the order
        is >> c.elixir >> c.health >> c.attack >> c.defense;
        is >> std::ws;

        // Extract name
        std::string word;
        std::vector<std::string> parts;
        while (is >> word) parts.push_back(word);

        if (parts.size() < 4) continue; // skip malformed lines

        // The last three are role, emoji, rarity
        c.rarity = parts.back(); parts.pop_back();
        c.emoji = parts.back(); parts.pop_back();
        c.role = parts.back(); parts.pop_back();

        // The rest form the name
        c.name.clear();
        for (size_t i = 0; i < parts.size(); ++i) {
            c.name += parts[i];
            if (i < parts.size() - 1) c.name += " ";
        }

        cards.push_back(c);
    }

    return cards;
}

// Random selection
std::vector<Card> selectRandomCards(std::vector<Card>& allCards, int n) {
    std::vector<Card> selected = allCards;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(selected.begin(), selected.end(), g);

    if (n < static_cast<int>(selected.size()))
        selected.resize(n);

    return selected;
}

// Helper for name formatting
std::string formatName(const std::string& name, int width = 15) {
    if (name.size() > width - 2)
        return name.substr(0, width - 2) + ".";
    return name;
}

// Player Draft
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
                      << " (" << c.elixir << " Elixir, "
                      << c.health <<  "Health, "
                      << c.attack << " Attack, "
                      << c.defense << " Defence, "
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

        // Remove chosen card from pool
        availableCards.erase(availableCards.begin() + chosenIndex);
    }

    return playerDeck;
}

// Save Deck to File
void saveDeckToFile(const std::string& filename, const std::vector<Card>& deck, const std::string& playerName) {
    std::ofstream out(filename, std::ios::app);
    if (!out) return;
    out << "\n=== " << playerName << " Deck ===\n";
    for (const auto& c : deck)
        out << c.name << " (" << c.elixir << " Elixir, " 
            << c.health << "Health, "
            << c.attack << " Attack, " << c.defense << " Defence, " 
            << c.rarity << " " << c.emoji << ", " << c.role << ")\n";
}

void gradeDeckResults(const std::vector<Card>& draftedDeck, const std::string& playerName) {
    Deck deck;

    // Convert each Card struct to a Cards object for Deck
    for (const auto& c : draftedDeck) {
        Cards cardObj(
            c.elixir,
            c.health,
            c.attack,
            c.defense,
            c.name,
            c.emoji,
            c.role,
            c.rarity
        );

        deck.addCard(cardObj);
    }

    DeckGrader grader;
    std::cout << std::fixed << std::setprecision(1);// set to 1 decimal point

    std::cout << "\n--- " << playerName << " Deck Grading ---\n";
    std::cout << "Average Elixir: " << grader.getAvgElixir(deck) << "\n";
    std::cout << "Balance Score: " << grader.gradeBalance(deck) << "\n";
    std::cout << "Attack Score: " << grader.gradeAttack(deck) << "\n";
    std::cout << "Defense Score: " << grader.gradeDefense(deck) << "\n";
    std::cout << "Strength Score: " << grader.gradeStrength(deck) << "\n";

    double totalScore = grader.gradeDeck(deck);
    std::cout << "Overall Deck Score: " << totalScore << "\n";

    // Deck grading feedback
    if (totalScore < 150)
        std::cout << "⭐️\n";
    else if (totalScore < 175)
        std::cout << "⭐️⭐️\n";
    else if (totalScore < 200)
        std::cout << "⭐️⭐️⭐️\n";
    else if (totalScore < 225)
        std::cout << "⭐️⭐️⭐️⭐️\n";
    else
        std::cout << "⭐️⭐️⭐️⭐️⭐️\n";
}