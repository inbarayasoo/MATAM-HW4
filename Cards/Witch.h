#ifndef CARD_H_VAMPIRE_H
#define CARD_H_VAMPIRE_H

#include "Battlecards.h"

const int INITIAL_FORCE_WITCH = 11;
const int INITIAL_LOOT_WITCH = 2;
const int INITIAL_DAMAGE_WITCH = 10;

class Witch : public Battlecards {
public:
    Witch();
    Witch(const Witch&) = default;
    ~Witch() override = default;
    Witch& operator=(const Witch& other) = default;
};

#endif //CARD_H_VAMPIRE_H
