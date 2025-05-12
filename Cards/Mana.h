
#ifndef CARD_H_FAIRY_H
#define CARD_H_FAIRY_H

#include "Card.h"
#include "../Players/Healer.h"

const int HEAL = 10;

class Mana : public Card {
public:
    Mana();
    Mana(const Mana&) = default;
    ~Mana() override = default;
    Mana& operator=(const Mana& other) = default;
    void applyEncounter(Player& player) const override;
};

#endif //CARD_H_FAIRY_H
