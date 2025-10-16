#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string>

class Cards {
    private:
    int Health;
    int Attack;
    int Defence;
    int Elixir;
    std::string Name;
    std::string Rarity;
    std::string Role;

    public:
    Cards(int Elix, int He, int Att, int Def, const std::string& n, const std::string& r, const std::string& rare);

    void setCardElixir(int Elix);
    int getCardElixir() const;

    void setCardHealth(int He);
    int getCardHealth() const;

    void setCardAttack(int Att);
    int getCardAttack() const;

    void setCardDefence(int Def);
    int getCardDefence() const;

    void SetCardName(const std::string& n);
    std::string getCardName() const;

    void SetCardRole(const std::string& r);
    std::string getCardRole() const;

    void SetCardRare(const std::string& rare);
    std::string getCardRare() const;

    void display() const;

    virtual ~Cards() = default;
};

#endif