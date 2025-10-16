// deck_grader.cpp
// ------------------------------------------------------------
// A tiny Clash Royale deck grading demo.
// - Reads a plain-text file of card blocks separated by a line with "---"
// - Parses fields like name, attack, defense, elixir, rarity, role
// - Validates & stores each Card
// - Grades a deck of up to 8 cards with a simple heuristic
// - Prints per-card summary and overall letter grade
//
// Example input file (save as cards.txt):
// ------------------------------------------------------------
// name=Knight
// attack=60
// defense=70
// elixir=3
// rarity=Common
// role=Tank
// ---
// name=Archers
// attack=55
// defense=40
// elixir=3
// rarity=Common
// role=Ranged
// ---
// name=Fireball
// attack=80
// defense=20
// elixir=4
// rarity=Rare
// role=Spell
// ---
// name=Mini P.E.K.K.A
// attack=85
// defense=35
// elixir=4
// rarity=Rare
// role=SingleTarget
// ---
// name=Skeleton Army
// attack=65
// defense=25
// elixir=3
// rarity=Epic
// role=Swarm
// ---
// name=Musketeer
// attack=75
// defense=40
// elixir=4
// rarity=Rare
// role=Ranged
// ---
// name=Valkyrie
// attack=70
// defense=60
// elixir=4
// rarity=Rare
// role=Splash
// ---
// name=Zap
// attack=50
// defense=20
// elixir=2
// rarity=Common
// role=Spell
// ------------------------------------------------------------
// Compile & run:
//   g++ -std=c++17 deck_grader.cpp -o deck_grader
//   ./deck_grader cards.txt
// ------------------------------------------------------------

#include <algorithm>
#include <cctype>
#include <exception>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Card {
    std::string name;
    int attack = 0;   // 0-100 (toy scale)
    int defense = 0;  // 0-100 (toy scale)
    int elixir = 0;   // typical 1-9 range
    std::string rarity; // Common / Rare / Epic / Legendary (optional)
    std::string role;   // e.g., Tank, Spell, Ranged, Splash, etc. (optional)
};

static inline std::string ltrim(std::string s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return s;
}

static inline std::string rtrim(std::string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

static inline std::string trim(std::string s) {
    return rtrim(ltrim(std::move(s)));
}

static inline std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    return s;
}

// Parse a key=value line; return {key, value} if valid
static std::optional<std::pair<std::string, std::string>> parseKV(const std::string& line) {
    auto pos = line.find('=');
    if (pos == std::string::npos) return std::nullopt;
    std::string key = trim(line.substr(0, pos));
    std::string val = trim(line.substr(pos + 1));
    if (key.empty()) return std::nullopt;
    return std::make_pair(key, val);
}

static int parseInt(const std::string& s) {
    // robust-ish integer parse
    std::size_t idx = 0;
    int value = 0;
    try {
        value = std::stoi(s, &idx, 10);
    } catch (...) {
        throw std::runtime_error("Invalid integer: '" + s + "'");
    }
    if (idx != s.size()) throw std::runtime_error("Invalid integer (extra chars): '" + s + "'");
    return value;
}

static Card buildCardFromMap(const std::unordered_map<std::string, std::string>& kv) {
    Card c;

    auto get = [&](const std::string& k) -> std::optional<std::string> {
        auto it = kv.find(k);
        if (it == kv.end()) return std::nullopt;
        return it->second;
    };

    if (auto v = get("name")) c.name = *v; else throw std::runtime_error("Missing required field: name");
    if (auto v = get("attack")) c.attack = parseInt(*v); else throw std::runtime_error("Missing required field: attack");
    if (auto v = get("defense")) c.defense = parseInt(*v); else throw std::runtime_error("Missing required field: defense");
    if (auto v = get("elixir")) c.elixir = parseInt(*v); else throw std::runtime_error("Missing required field: elixir");

    if (auto v = get("rarity")) c.rarity = *v; else c.rarity = "";
    if (auto v = get("role"))   c.role   = *v; else c.role   = "";

    // toy validation
    if (c.attack < 0 || c.attack > 100) throw std::runtime_error("attack out of range 0..100 for '" + c.name + "'");
    if (c.defense < 0 || c.defense > 100) throw std::runtime_error("defense out of range 0..100 for '" + c.name + "'");
    if (c.elixir < 1 || c.elixir > 10) throw std::runtime_error("elixir out of range 1..10 for '" + c.name + "'");

    return c;
}

static std::vector<Card> loadCards(const std::string& path) {
    std::ifstream in(path);
    if (!in) throw std::runtime_error("Cannot open file: " + path);

    std::vector<Card> out;
    std::unordered_map<std::string, std::string> kv;

    auto flushBlock = [&]() {
        if (kv.empty()) return; // allow consecutive separators
        try {
            out.push_back(buildCardFromMap(kv));
        } catch (const std::exception& e) {
            throw std::runtime_error(std::string("Error in card block #") + std::to_string(out.size()+1) + ": " + e.what());
        }
        kv.clear();
    };

    std::string line;
    while (std::getline(in, line)) {
        line = trim(line);
        if (line.empty()) continue; // ignore blank lines
        if (line == "---") { flushBlock(); continue; }
        if (line.rfind("//", 0) == 0) continue; // ignore comments starting at column 1

        if (auto kvp = parseKV(line)) {
            std::string key = toLower(kvp->first);
            kv[key] = kvp->second; // last-one-wins
        } else {
            throw std::runtime_error("Expected key=value or '---', got: " + line);
        }
    }
    // last block (EOF)
    flushBlock();

    return out;
}

// Simple deck grading heuristic (0..100) + letter
struct Grade { double score; char letter; };

static Grade gradeDeck(const std::vector<Card>& deck) {
    if (deck.empty()) return {0.0, 'F'};

    const int n = static_cast<int>(deck.size());
    double sumAtk = 0, sumDef = 0, sumElixir = 0;
    std::unordered_set<std::string> roles;

    for (const auto& c : deck) {
        sumAtk += c.attack;
        sumDef += c.defense;
        sumElixir += c.elixir;
        if (!c.role.empty()) roles.insert(toLower(c.role));
    }

    const double atkAvg = sumAtk / n;   // target ~70
    const double defAvg = sumDef / n;   // target ~60
    const double elixirAvg = sumElixir / n; // target ~3.5..4.0

    // Scores (clipped 0..100), with soft penalties for deviating from targets
    auto clamp01 = [](double x){ return std::max(0.0, std::min(1.0, x)); };

    double atkScore = clamp01(1.0 - std::abs(atkAvg - 70.0) / 40.0) * 35.0;
    double defScore = clamp01(1.0 - std::abs(defAvg - 60.0) / 40.0) * 25.0;

    // elixir sweet spot around 3.5-4.0 -> triangular bonus
    double elixirPenalty = std::abs(elixirAvg - 3.75); // 0 at 3.75
    double elixirScore = clamp01(1.0 - elixirPenalty / 1.75) * 25.0;

    // role diversity bonus (encourage 5+ unique roles)
    double diversity = static_cast<double>(roles.size());
    double diversityScore = clamp01((diversity - 3.0) / 3.0) * 15.0;

    double total = atkScore + defScore + elixirScore + diversityScore; // 0..100

    char letter;
    if      (total >= 90) letter = 'S'; // fun "S-tier"
    else if (total >= 80) letter = 'A';
    else if (total >= 70) letter = 'B';
    else if (total >= 60) letter = 'C';
    else if (total >= 50) letter = 'D';
    else                  letter = 'F';

    return { total, letter };
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <cards.txt>\n";
        return 1;
    }

    try {
        auto cards = loadCards(argv[1]);
        if (cards.empty()) {
            std::cerr << "No cards loaded.\n";
            return 2;
        }

        std::cout << "Loaded " << cards.size() << " card(s):\n";
        for (const auto& c : cards) {
            std::cout << " - " << c.name
                      << " | atk=" << c.attack
                      << ", def=" << c.defense
                      << ", elixir=" << c.elixir
                      << (c.rarity.empty() ? "" : (", rarity=" + c.rarity))
                      << (c.role.empty()   ? "" : (", role=" + c.role))
                      << "\n";
        }

        // If more than 8 cards, just grade the first 8 for this demo
        if (cards.size() > 8) {
            std::cout << "\nNote: Truncating to first 8 cards for grading demo.\n";
            cards.resize(8);
        }

        auto g = gradeDeck(cards);
        std::cout << "\nDeck score: " << g.score << "/100\n";
        std::cout << "Letter grade: " << g.letter << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 3;
    }

    return 0;
}
