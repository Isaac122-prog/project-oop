#ifndef RANGEDTROOP_H
#define RANGEDTROOP_H
#include "Troop.h"

class Ranged_troop : public Troop {
    private:
    int Attack_range, Projectile_speed;

    public:
    Ranged_troop(int Attack_range, int Projectile_speed);
    int Get_Attack_range() const;
    int Get_Projectile_speed() const;

    void Set_Attack_range(int Attack_range);
    void Set_Projectile_speed(int Projectile_speed);
};

#endif
