#ifndef TANKTROOP_H
#define TANKTROOP_H
#include "Troop.h"

class Tank_troop : public Troop {
    private:
    int Health_points, Damage;

    public:
    int Get_Health_points() const;
    int Get_Damage() const;

    void Set_Health_points(int Health_points);
    void Set_Damage(int Damage);
};

#endif