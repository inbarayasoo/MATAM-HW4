#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H

#include "Player.h"

class Warrior : public Player {
public:
    Warrior(std::string name);
    ~Warrior() override = default;
    Warrior(const Warrior&) = default;
    Warrior& operator=(const Warrior& other) = default;
    void printInfoPlayer(std::ostream& os) const;
    int getAttackStrength() const override;
    std::string getPlayerJob() override;



};
#endif //EX4_WARRIOR_H
