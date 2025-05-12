#include "Mana.h"
#include "../utilities.h"

Mana::Mana() : Card("Mana") {}

void Mana::applyEncounter(Player& player) const
{
    bool isHealer = false;
    if(dynamic_cast<Healer*>(&player) != nullptr){
        player.heal(HEAL);
        isHealer = true;
    }
    printManaMessage(isHealer);
}
