#include "Defensive_Building.h"

// Constructor
Defensive_Building::Defensive_Building(int lifetime, int decayRate, int damagePerShot)
    : Building(lifetime, decayRate), Damage_Per_Shot(damagePerShot) {}

// Returns the building’s damage per shot
int Defensive_Building::Get_Damage_Per_Shot() const {
    return Damage_Per_Shot;
}

// Optional setter function
void Defensive_Building::Set_Damage_Per_Shot(int damagePerShot) {
    Damage_Per_Shot = damagePerShot;
}
