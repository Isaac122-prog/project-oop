#include "Spawner_Building.h"

// Constructor
Spawner_Building::Spawner_Building(int lifetime, int decayRate, int spawnRate)
    : Building(lifetime, decayRate), Spawn_Rate(spawnRate) {}

// Returns the number of troops spawned per time
int Spawner_Building::Get_Spawn_Rate() const {
    return Spawn_Rate;
}

// Optional setter function
void Spawner_Building::Set_Spawn_Rate(int spawnRate) {
    Spawn_Rate = spawnRate;
}
