#include "Tank_troop.h"

//constructor
Tank_troop::Tank_troop(int Health_points, int Damage)
    : Health_points(Health_points), Damage(Damage){}


int Tank_troop::Get_Health_points() const {
    return Health_points;
}

int Tank_troop::Get_Damage() const {
    return Damage;
}

void Tank_troop::Set_Health_points(int Health_points){
    this -> Health_points = Health_points;
}

void Tank_troop::Set_Damage(int Damage){
    this -> Damage = Damage;
}
