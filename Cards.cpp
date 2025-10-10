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