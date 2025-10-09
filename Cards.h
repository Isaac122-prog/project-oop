#ifndef CARDS_H
#define CARDS_H
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
};

#endif