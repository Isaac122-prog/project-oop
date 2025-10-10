#include "Resource_Building.h"

Resource_Building::Resource_Building(int lifetime, int decay, int Elixir_produced)
    : Building(lifetime, decayRate), Elixir_Produced(Elixir_produced) {}

int Resource_Building::Get_Elixir_Produced() const {
    return Elixir_produced;
}

void Resource_Building::Set_Elixir_Produced(int Elixir_produced) {
    Elixir_Produced = Elixir_produced;
}

