#include "Ranged_troop.h"

Ranged_troop::Ranged_troop(int Attack_range, int Projectile_speed)
    : Attack_range(Attack_range), Projectile_speed(Projectile_speed) {}

int Ranged_troop::Get_Attack_range() const{
    return Attack_range;
}

int Ranged_troop::Get_Projectile_speed() const{
    return Projectile_speed;
}

void Ranged_troop::Set_Attack_range(int Attack_range){
    this -> Attack_range = Attack_range;
}

void Range_troop::Set_Projectile_speed(int Projectile_speed){
    this -> Projectile_speed = Projectile_speed;
}
