#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>

class Deck {
protected:
    std::vector<Cards*> deckCards;
    std::string Deck_Name;

public:
    Deck(std::string name = "");

    bool Add_Cards(Cards* card);
    bool Remove_Cards(Cards* card);
    void Set_Deck_Name(const std::string& name);
    std::string Get_Deck_Name() const;

    const std::vector<Cards*>& Get_Cards() const;
};

#endif


