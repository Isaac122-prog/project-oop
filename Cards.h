#ifndef CARDS_H
#define CARDS_H
<<<<<<< HEAD
#include <iostream>
#include <string>

class Cards{
    private:
        int attack;
        int defence;
        int elixir;
        int health;
        std::string card_name;
        std::string role;
    public:
        Cards(int Att, int Def, int Elix, int He, const std::string& name, const std::string& r);

        void setCardAttack(int Att);
        int getCardAttack() const;

        void setCardDefence(int Def);
        int getCardDefence() const;

        void setCardElixir(int Elix);
        int getCardElixir() const;        

        void setCardHealth(int He);
        int getCardHealth() const;

        void setCardName(const std::string& name);
        std::string getNameConst() const;

        void setCardRole(const std::string& r);
        std::string getRole() const;

        void display() const;

        virtual ~Cards() = default;
=======
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
>>>>>>> 277870e63537a1b272b059d77d41513d6134ed54
};

#endif