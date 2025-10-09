#include "Deck.h"

Deck::Deck(){}

std::string Deck::get_card_ID() const {
    return Card_ID;
}

std::string Cards::get_card_name() const {
    return Card_name;
}

std::string Cards::get_card_rarity() const {
    return Rarity;
}

int Cards::get_card_elixir() const {
    return Elixir_cost;
}

int Cards::get_health() const {
    return Health;
}

std::string Cards::get_card_role() const {
    return Role;
}
