#ifndef EX4_NINJA_H
#define EX4_NINJA_H
#include "Player.h"

class Ninja : public Player {
public:
    Ninja(std::string name);
    ~Ninja() override = default;
    Ninja(const Ninja&) = default;
    Ninja& operator=(const Ninja& other) = default;
    void addCoins(int coins) override;
    void printInfoPlayer(std::ostream& os) const override;
    std::string getPlayerJob() override;

};
#endif //EX4_NINJA_H
