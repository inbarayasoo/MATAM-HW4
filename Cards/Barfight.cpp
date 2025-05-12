#include "Barfight.h"
#include "../utilities.h"

void Barfight::applyEncounter(Player& player) const
{
    bool isFighter = true;
    if(dynamic_cast<Warrior*>(&player) == nullptr){
        player.damage(DAMAGE);
        isFighter = false;
    }
    printBarfightMessage(isFighter);
}

Barfight::Barfight() : Card("Barfight") {}
