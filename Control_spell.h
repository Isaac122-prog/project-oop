#ifndef CONTROLSPELLS_H
#define CONTROLSPELLS_H
#include <string>

class Control_spell : public Spell {
    private:
    std::string Control_Effect;

    public:
    std::string Get_Control_Effect;
    std::string Set_Control_Effect;
};

#endif
