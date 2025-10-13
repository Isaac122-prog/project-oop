#include "Melee_troop.h"

Melee_troop(int Attack_speed)
    : Attack_speed(Attack_speed) {}

int Melee_troop::Get_Attack_speed() const{
    return Attack_speed;
}

void Melee_troop::Set_Attack_speed(int Attack_speed) {
    this -> Attack_speed = Attack_speed;
}