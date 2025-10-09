#ifndef BUILDING_H
#define BUILDING_H

#include "Cards.h"

class Building : public Cards {
private:
    int lifetime;
    int decayRate;

public:
    Building(int lifetime, int decayRate);

    int Get_Lifetime() const;
    int Get_Decay_Rate() const;

    void Set_Lifetime(int lifetime);
    void Set_Decay_Rate(int decayRate);
};

#endif
