#include "Control_spell.h"
#include <string>

Control_spell::Get_Control_Effect(){
    return Control_spell;
}

Control_spell::Set_Control_Effect(std::string Control_spell){
    this -> Control_spell = Control_spell;
}
