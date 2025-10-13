<<<<<<< HEAD
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

=======
#include "Cards.h"
#include <string>

Cards::Cards(std::string Card_ID, std::string Card_name, std::string Rarity, std::string Role, int Elixir_cost, int Health)
    : Card_ID(Card_ID), Card_name(Card_name), Rarity(Rarity), Role(Role), Elixir_cost(Elixir_cost), Health(Health) {}

std::string Cards::Get_Card_ID(){
    return Card_ID;
}

std::string Cards::Get_Card_name(){
    return Card_name;
}

std::string Cards::Get_Rarity(){
    return Rarity;
}

std::string Cards::Get_Role(){
    return Role;
}

int Cards::Get_Elixir_cost(){
    return Elixir_cost;
}

int Cards::Get_Health(){
    return Health;
}
>>>>>>> 277870e63537a1b272b059d77d41513d6134ed54
