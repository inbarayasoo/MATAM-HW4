#ifndef CARD_H_BARFIGHT_H
#define CARD_H_BARFIGHT_H

#include "Card.h"
#include "../Players/Warrior.h"
int const DAMAGE = 10;

class Barfight : public Card {
public:
    Barfight();
    Barfight(const Barfight&) = default;
    ~Barfight() override = default;
    Barfight& operator=(const Barfight& other) = default;
    void applyEncounter(Player& player) const override;
};

#endif //CARD_H_BARFIGHT_H
