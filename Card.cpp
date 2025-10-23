#include "Card.h"

//initialising variables
Card::Card(int el, int he, int att, int def,
           const std::string& n,
           const std::string& r,
           const std::string& tr,
           const std::string& rare)
    : elixir(el), health(he), attack(att), defence(def),
      name(n), role(r), tripRole(tr), rarity(rare) {}

//getters
int Card::getElixir() const { return elixir; }
int Card::getHealth() const { return health; }
int Card::getCardAttack() const { return attack; }
int Card::getDefence() const { return defence; }
std::string Card::getName() const { return name; }
std::string Card::getRole() const { return role; }
std::string Card::getTripRole() const { return tripRole; }
std::string Card::getRarity() const { return rarity; }
