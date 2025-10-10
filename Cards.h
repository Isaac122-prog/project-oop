#ifndef CARDS_H
#define CARDS_H
#include <string>

class Cards {
    private:
    std::string Card_ID, Card_name, Rarity, Role;
    int Elixir_cost, Health;

    public:
    std::string Get_Card_ID;
    std::string Get_Card_name;
    std::string Get_Rarity;
    std::string Get_Role;
    int Get_Elixir_cost;
    int Get_Health;
};

#endif