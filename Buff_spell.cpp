#include "Buff_spell.h"

Buff_spell::Buff_spell(std::string Buff_Type, int Buff_amount, int Duration)
    :   Buff_Type(Buff_Type), Buff_amount(Buff_amount), Duration(Duration) {}

std::string Buff_spell::Get_Buff_Type(){
    return Buff_Type;
}

int Buff_spell::Get_Buff_amount() const {
    return Buff_amount;
}

int Buff_spell::Get_Duration() const {
    return Duration;
}

void Buff_spell::Set_Buff_Type(){
    this -> Buff_Type = Buff_Type;
}

void Buff_spell::Set_Buff_amount(int Buff_amount){
    this -> Buff_amount = Buff_amount;
}

void Buff_spell::Set_Duration(int Duration){
    this -> Duration = Duration;
}