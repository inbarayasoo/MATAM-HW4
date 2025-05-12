#include "Ninja.h"
#include "../utilities.h"

using std::string;
const string NINJA_NAME = "Ninja";

Ninja::Ninja (string name) : Player(name)
{}

void Ninja::addCoins(int coins)
{
    if (coins <= 0) {
        coins = 0;
    }
    m_coins = m_coins + MULTIPLY_BY_TWO * coins;
}

void Ninja::printInfoPlayer(std::ostream& os) const
{
    printPlayerDetails(os, m_name, NINJA_NAME, m_level, m_force, m_hp, m_coins);
}

string Ninja::getPlayerJob()
{
    return NINJA_NAME;
}

