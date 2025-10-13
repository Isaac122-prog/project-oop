#include "Spell.h"

//constructor
Spell::Spell(int Effect_area, int Duration, int Damage_amount)
    : Effect_area(Effect_area), Duration(Duration), Damage_amount(Damage_amount) {}


int Spell::Get_Effect_area() const {
    return Effect_area;
}

int Spell::Get_Duration() const {
    return Duration;
}

int Spell::Get_Damage_amount() const {
    return Damage_amount;
}

void Spell::Set_Effect_area(int Effect_area){
    this -> Effect_area = Effect_area;
}

void Spell::Set_Duration(int Duration){
    this -> Duration = Duration;
}

void Spell::Set_Damage_amount(int Damage_amount){
    this -> Damage_amount = Damage_amount;
}
