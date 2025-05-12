#include "Treasure.h"
#include "../utilities.h"

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(this->m_loot);
    printTreasureMessage();
}

Treasure::Treasure() : Card("Treasure") , m_loot(LOOT) {}