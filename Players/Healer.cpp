#include "Healer.h"
#include "../utilities.h"

using std::string;
const string HEALER_NAME = "Healer";

Healer::Healer (string name) : Player(name)
{}

void Healer::heal(int hp)
{
    if(hp <= 0) {
        hp = 0;
    }
    int tempHp = m_hp + MULTIPLY_BY_TWO * hp;
    if (tempHp <= m_maxHP) {
        m_hp = tempHp;
    }
    else {
        m_hp = m_maxHP;
    }
}

void Healer::printInfoPlayer(std::ostream& os) const
{
    printPlayerDetails(os, m_name, HEALER_NAME, m_level, m_force, m_hp, m_coins);
}

string Healer::getPlayerJob()
{
    return HEALER_NAME;
}
