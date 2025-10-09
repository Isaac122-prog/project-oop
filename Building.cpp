#include "Building.h"

// Constructor
Building::Building(int lifetime, int decayRate)
    : lifetime(lifetime), decayRate(decayRate) {}

// Returns the building's lifetime (health)
int Building::Get_Lifetime() const {
    return lifetime;
}

// Returns the building's decay rate
int Building::Get_Decay_Rate() const {
    return decayRate;
}

// Optional setter functions
void Building::Set_Lifetime(int lifetime) {
    this->lifetime = lifetime;
}

void Building::Set_Decay_Rate(int decayRate) {
    this->decayRate = decayRate;
}
