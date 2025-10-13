#ifndef SPELL_H
#define SPELL_H
#include "Cards.h"

class Spell : public Cards {
    private:
    int Effect_area, Duration, Damage_amount;

    public:
    Spell(int Effect_area, int Duration, int Damage_amount);

    int Get_Effect_area() const;
    int Get_Duration() const;
    int Get_Damage_amount() const;

    void Set_Effect_area(int Effect_area);
    void Set_Duration(int Duration);
    void Set_Damage_amount(int Damage_amount);
}
#endif
