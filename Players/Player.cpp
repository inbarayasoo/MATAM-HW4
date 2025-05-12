#include "Player.h"

using std::string;

Player::Player(string name) : m_name(name),
        m_level(STARTING_LEVEL), m_force(DEFAULT_FORCE), m_maxHP(DEFAULT_MAX_HP), m_hp(DEFAULT_MAX_HP),
        m_coins(STARTING_COINS)
{}

std::ostream& operator<<(std::ostream& os, const Player& job)
{
    job.printInfoPlayer(os);
    return os;
}

void Player::levelUp()
{
    if(m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int force)
{
    if(force > 0)
    {
        m_force = force + m_force;
    }
}

void Player::heal(int hp)
{
    if(hp <= 0)
    {
        hp = 0;
    }
    int tempHp = m_hp + hp;
    if (tempHp <= m_maxHP)
    {
        m_hp = tempHp;
    }
    else
    {
        m_hp = m_maxHP;
    }
}

void Player::damage(int hp)
{
    if(hp <= 0)
    {
        hp = 0;
    }

    if (m_hp > hp)
    {
        m_hp = m_hp - hp;
    }
    else
    {
        m_hp = 0;
    }
}

bool Player::isKnockedOut() const
{
    return m_hp <= 0;
}

void Player::addCoins(int coins)
{
    if (coins > 0)
    {
        m_coins = m_coins + coins;
    }
}

bool Player::pay(int coins)
{
    if (coins <= 0) {
        coins = 0;
    }
    if (m_coins < coins) {
        return false;
    }
    m_coins = m_coins - coins;
    return true;
}

int Player::getAttackStrength() const
{
    return (m_force + m_level);
}


string Player::getPlayerName() const
{
    return m_name;
}

void Player::decreaseForce()
{
    if(m_force == 0)
    {
        return;
    }
    m_force--;
}
int Player::getPlayerCoins() const
{
    return m_coins;
}
