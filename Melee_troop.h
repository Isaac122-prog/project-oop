#ifndef MELLEETROOP_H
#define MELLEETROOP_H

class Melee_troop : public Troop {
    private:
    int Attack_speed;

    public:
    int Get_Attack_speed() const;

    void Set_Attack_speed(int Attack_speed);
};

#endif

