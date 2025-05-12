
#ifndef CARD_H_GOBLIN_H
#define CARD_H_GOBLIN_H

#include "Battlecards.h"

const int INITIAL_FORCE_GOBLIN = 5;
const int INITIAL_LOOT_GOBLIN = 2;
const int INITIAL_DAMAGE_GOBLIN = 10;

class Gremlin : public Battlecards {
public:
    Gremlin();
    Gremlin(const Gremlin&) = default;
    ~Gremlin() override = default;
    Gremlin& operator=(const Gremlin& other) = default;
};

#endif //CARD_H_GOBLIN_H
