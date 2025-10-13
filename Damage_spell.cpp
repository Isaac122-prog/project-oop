#include "Damage_spell.h"

Damage_spell::Damage_spell(int Troops_Spawn, int Trap)
    : Troops_Spawn(Troops_Spawn), Trap(Trap) {}

int Damage_spell::Get_Troops_Spawn() const {
    return Troops_Spawn;
}

int Damage_spell::Get_Trap() const {
    return Trap;
}

void Damage_spell::Set_Troops_Spawn(int Troops_spawn) {
    this -> Troops_Spawn = Troops_Spawn;
}

void Damage_spell::Set_Trap(int Trap) {
    this -> Trap = Trap;
}