#include "Troop.h"

Troop::Troop(int health, int damage, int range, int speed)
    : health(health), damage(damage), range(range), speed(speed) {}

int Troop::Get_health() const {
    return health;
}

int Troop::Get_damage() const {
    return damage;
}

int Troop::Get_range() const {
    return range;
}

int Troop::Get_speed() const {
    return speed;
}

void Troop::Set_health(int health) {
    this -> health = health;
}

void Troop::Set_damage(int damage) {
    this -> damage = damage;
}

void Troop::Set_range(int range) {
    this -> range = range;
}

void Troop::Set_speed(int speed) {
    this -> speed = speed;
}
 