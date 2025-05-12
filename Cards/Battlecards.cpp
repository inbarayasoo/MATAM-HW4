#include "Battlecards.h"
#include "../utilities.h"
using namespace std;

void Battlecards::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= this->m_force) {
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getPlayerName(), this->m_name);
    }
    else {
        if(this->m_name == "Witch") {
            player.decreaseForce();
        }
        player.damage(this->m_hpLossOnDefeat);
        printLossBattle(player.getPlayerName(), this->m_name);
    }
}

void Battlecards::printInfo(ostream& os) const
{
    printCardDetails(os,this->m_name);
    bool isDragon = false;
    if(this->m_name == "Dragon") {
        isDragon = true;
    }
    printMonsterDetails(os,this->m_force,this->m_hpLossOnDefeat,this->m_loot,isDragon);
    printEndOfCardDetails(os);
}

Battlecards::Battlecards(const string name , int force , int loot , int hpLossOnDefeat): Card(name) ,
m_force(force) , m_loot(loot) , m_hpLossOnDefeat(hpLossOnDefeat) {}