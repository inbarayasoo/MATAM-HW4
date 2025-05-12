#include "Well.h"
#include "../utilities.h"

Well::Well() : Card("Well") {}

void Well::applyEncounter(Player& player) const
{
    bool isNinja = true;
    if(dynamic_cast<Ninja*>(&player) == nullptr){
        player.damage(DAMAGE_BY_WELL);
        isNinja = false;
    }
    printWellMessage(isNinja);
}
