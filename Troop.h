#ifndef TROOP_H
#define TROOP_H
#include "Cards.h"

class Troop : public Cards {
    private:
    int health, damage, speed, range;

    public:
    Troop(int health, int damage, int speed, int range);

    int Get_health() const;
    int Get_damage() const;
    int Get_speed() const;
    int Get_range() const;

    void Set_health(int health);
    void Set_damage(int damage);
    void Set_speed(int speed);
    void Set_range(int range);

};

#endif
