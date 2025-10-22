#include <iostream>
#include <string>
#include <iomanip>

#include "Cards.h"

Cards::Cards(int Elix, int He, int Att, int Def, const std::string& n, const std::string& T_Role, const std::string& r, const std::string& rare)
    : Attack(Att), Defence(Def), Elixir(Elix), Health(He), Name(n), Trip_Role(T_Role), Role(r), Rarity(rare) {}


void Cards::setCardAttack(int Att){
    Attack = Att;
}

void Cards::setCardDefence(int Def){
    Defence = Def;
}

void Cards::setCardElixir(int Elix){
    Elixir = Elix;
}

void Cards::setCardHealth(int He){
    Health = He;
}

void Cards::SetCardName(const std::string& n){
    Name = n;
}

void Cards::SetCardRole(const std::string& r){
    Role = r;
}

void Cards::SetCardTripleDraftRole(const std::string& T_Role){
    Trip_Role = T_Role;
}

int Cards::getCardAttack() const{
    return Attack;
}

int Cards::getCardDefence() const{
    return Defence;
}

int Cards::getCardElixir() const{
    return Elixir;
}

int Cards::getCardHealth() const{
    return Health;
}

std::string Cards::getCardName() const{
    return Name;
}

std::string Cards::getCardRare() const{
    return Rarity;
}

std::string Cards::getCardRole() const{
    return Role;
}

std::string Cards::getCardTripleDraftRole() const{
    return Trip_Role;
}

void Cards::display() const{
    std::cout << "Name: " << Name
              << ", Elixir: " << Elixir
              << ", Attack: " << Attack
              << ", Defence: " << Defence 
              << ", Health: " << Health
              << ", Triple Draft Role: " << Trip_Role
              << ", Role: " << Role
              << ", Rarity: " << Rarity << std::endl;
}

