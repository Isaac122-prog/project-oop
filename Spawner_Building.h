#ifndef SPAWNER_BUILDING_H
#define SPAWNER_BUILDING_H

#include "Building.h"

class Spawner_Building : public Building {
private:
    int Spawn_Rate;

public:
    // Constructor
    Spawner_Building(int lifetime, int decayRate, int spawnRate);

    // Getter
    int Get_Spawn_Rate() const;

    // (Optional) Setter
    void Set_Spawn_Rate(int spawnRate);
};

#endif