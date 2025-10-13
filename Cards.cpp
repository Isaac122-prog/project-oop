#include <iostream>
#include <string>
#include "Cards.h"

Cards::Cards(int Att, int Def, int Elix, int He, const std::string& name, const std::string& r)
    : attack(Att), defence(Def), elixir(Elix), health(He), card_name(name), role(r) {}


void Cards::setCardAttack(int Att){
    attack = Att;
}

void Cards::setCardDefence(int Def){
    defence = Def;
}

void Cards::setCardElixir(int Elix){
    elixir = Elix;
}

void Cards::setCardHealth(int He){
    health = He;
}

void Cards::setCardName(const std::string& name){
    card_name = name;
}

void Cards::setCardRole(const std::string& r){
    role = r;
}

void Cards::display() const{
    std::cout << "Name: " << card_name
              << ",Elixir " << elixir
              << ", Attack " << attack
              << ", Defence" << defence << std::endl;
}

