#ifndef BUFFSPELL_H
#define BUFFSPELL_H
#include "Spell.h"
#include <string>

class Buff_spell : public Spell {
    private:
    std::string Buff_Type;
    int Buff_amount, Duration;

    public:
    Buff_spell(std::string Buff_Type, int Buff_amount, int Duration);
    std::string Get_Buff_Type();
    int Get_Buff_amount() const;
    int Get_Duration() const;

    std::string Set_Buff_Type();
    void Set_Buff_amount(int Buff_amount);
    void Set_Duration(int Duration);

};
#endif
