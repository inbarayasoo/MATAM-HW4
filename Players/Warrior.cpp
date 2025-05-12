#include "Warrior.h"
#include "../utilities.h"

using std::string;
const string WARRIOR_NAME = "Warrior";

Warrior::Warrior (string name) : Player(name)
{}

int Warrior::getAttackStrength() const
{
    return (m_force * MULTIPLY_BY_TWO + m_level) ;
}

void Warrior::printInfoPlayer(std::ostream& os) const
{
    printPlayerDetails(os, m_name, WARRIOR_NAME, m_level, m_force, m_hp, m_coins);
}

string Warrior::getPlayerJob()
{
    return WARRIOR_NAME;
}


