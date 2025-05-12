#ifndef CARD_H_TREASURE_H
#define CARD_H_TREASURE_H

#include "Card.h"

int const LOOT = 10;

class Treasure : public Card {
public:
    Treasure();
    Treasure(const Treasure&) = default;
    ~Treasure() override = default;
    Treasure& operator=(const Treasure& other) = default;
    void applyEncounter(Player& player) const override;

private:
    int m_loot;
};

#endif //CARD_H_TREASURE_H
