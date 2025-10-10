#ifndef DAMAGESPELL_H
#define DAMAGESPELL_H
#include "Spell.h"

class Damage_spell : public Spell {
    private:
    int Troops_Spawn, Trap;

    public:
    Damage_spell(int Troops_Spawn, Trap);
    int Get_Troops_Spawn() const;
    int Get_Trap() const;

    void Set_Troops_Spawn(int Troops_Spawn);
    void Set_Trap(int Trap)

};

#endif
