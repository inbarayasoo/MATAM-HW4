#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H
#include <string>

int const MULTIPLY_BY_TWO = 2;
int const MAX_LEVEL = 10;
int const DEFAULT_MAX_HP = 100;
int const DEFAULT_FORCE = 5;
int const STARTING_LEVEL = 1;
int const STARTING_COINS = 10;

class Player {
public:

    explicit Player(std::string name);
    virtual ~Player() = default;
    Player(const Player& player) = default;
    Player& operator=(const Player& other) = default;
    virtual void addCoins(int coins);
    virtual int getAttackStrength() const;
    virtual void heal(int hp);
    virtual void printInfoPlayer(std::ostream& os) const = 0;
    virtual std::string getPlayerJob() = 0;
//    virtual Player* getPlayerType() = 0;
    void levelUp();
    int getLevel() const;
    void buff(int force);
    void damage(int hp);
    bool isKnockedOut() const ;
    bool pay(int coins);
    std::string getPlayerName() const;
    void decreaseForce();
    int getPlayerCoins() const ;


protected:

    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coins;
    friend std::ostream& operator<<(std::ostream& os, const Player& job);

};
#endif //EX4_PLAYER_H
