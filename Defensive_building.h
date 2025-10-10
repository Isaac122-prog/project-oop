#ifndef DEFENSIVE_BUILDING
#define DEFENSIVE_BUILDING
#include "Building.h"

class Defensive_building : public Building {
    private:
    int Damage_Per_Shot;

    public:
    Defensive_building(int Damage_Per_Shot);

    int get_Damage_Per_Shot() const;

    void set_Damage_Per_Shot(int Damage_Per_Shot);
};

#endif

