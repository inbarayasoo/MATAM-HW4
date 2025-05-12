#ifndef EX4_HEALER_H
#define EX4_HEALER_H
#include "Player.h"

class Healer : public Player {
public:
    Healer(std::string name);
    ~Healer() override = default;
    Healer(const Healer&) = default;
    Healer& operator=(const Healer& other) = default;
    void heal(int hp) override;
    void printInfoPlayer(std::ostream& os) const override;
    std::string getPlayerJob() override;

};
#endif //EX4_HEALER_H
