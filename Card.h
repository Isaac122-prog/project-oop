#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
protected:
    int elixir;
    int health;
    int attack;
    int defence;
    std::string name;
    std::string role;
    std::string tripRole;
    std::string rarity;

public:
    //default constructor
    Card() = default;
    //constructor
    Card(int elixir, int health, int attack, int defence,
         const std::string& name,
         const std::string& role,
         const std::string& tripRole,
         const std::string& rarity);

    // Virtual functions
    virtual int getElixir() const;
    virtual int getHealth() const;
    virtual int getCardAttack() const;
    virtual int getDefence() const;
    virtual std::string getName() const;
    virtual std::string getRole() const;
    virtual std::string getTripRole() const;
    virtual std::string getRarity() const;
    
    // Virtual destructor
    virtual ~Card() = default;
};

#endif