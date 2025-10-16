#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Card {
    std::string name;
    int elixir;
    int attack;
    int defense;
    std::string rarity;
    std::string tripleDraftRole;
    std::string role;
};

void saveCards(const std::vector<Card>& cards, const std::string& ) {
    std::ofstream out(Cards.txt);
    if (!out) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    for (const auto& c : cards) {
        out << "card name: " << c.name << "\n";
        out << "elixir: " << c.elixir << "\n";
        out << "attack: " << c.attack << "\n";
        out << "defense: " << c.defense << "\n";
        out << "rarity: " << c.rarity << "\n";
        out << "tripledraftrole: " << c.tripleDraftRole << "\n";
        out << "role: " << c.role << "\n";
        out << "-----\n"; // separator between cards
    }

    out.close();
    std::cout << "Cards saved successfully to " << filename << "\n";
}

// Load cards from readable format
std::vector<Card> loadCards(const std::string& filename) {
    std::ifstream in(filename);
    std::vector<Card> cards;
    Card c;
    std::string label;

    if (!in) {
        std::cerr << "Error opening file for reading.\n";
        return cards;
    }

    while (in >> label) {
        if (label == "card") { // "card name:"
            in.ignore(6, ':'); // skip " name:"
            std::getline(in >> std::ws, c.name);
        } else if (label == "elixir:") {
            in >> c.elixir;
        } else if (label == "attack:") {
            in >> c.attack;
        } else if (label == "defense:") {
            in >> c.defense;
        } else if (label == "rarity:") {
            std::getline(in >> std::ws, c.rarity);
        } else if (label == "tripledraftrole:") {
            std::getline(in >> std::ws, c.tripleDraftRole);
        } else if (label == "role:") {
            std::getline(in >> std::ws, c.role);
        } else if (label == "-----") {
            cards.push_back(c);
            c = {}; // reset for next card
        }
    }

    if (!c.name.empty()) cards.push_back(c); // add last card if file has no ending -----

    std::cout << "Cards loaded successfully from " << filename << "\n";
    return cards;
}

int main() {
    std::vector<Card> cards = {
        {"Ice Golem", 3, 10, 20, "Legendary", "MiniTank", "MiniTank"},
        {"Knight", 3, 12, 18, "Common", "Tank", "Melee"},
        {"Wizard", 5, 25, 10, "Rare", "Support", "Splash"}
    };

    std::string filename = "cards_data.txt";

    saveCards(cards, filename);

    std::vector<Card> loadedCards = loadCards(filename);

    std::cout << "\n=== Loaded Cards ===\n";
    for (const auto& c : loadedCards) {
        std::cout << "card name: " << c.name << "\n";
        std::cout << "elixir: " << c.elixir << "\n";
        std::cout << "attack: " << c.attack << "\n";
        std::cout << "defense: " << c.defense << "\n";
        std::cout << "rarity: " << c.rarity << "\n";
        std::cout << "tripledraftrole: " << c.tripleDraftRole << "\n";
        std::cout << "role: " << c.role << "\n";
        std::cout << "-----\n";
    }

    return 0;
}
