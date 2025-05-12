#ifndef CARD_H_DRAGON_H
#define CARD_H_DRAGON_H

#include "Battlecards.h"

int const INITIAL_FORCE = 25;
int const INITIAL_LOOT = 1000;
int const INITIAL_DAMAGE = 100;

class Dragon : public Battlecards {
public:
    Dragon();
    Dragon(const Dragon&) = default;
    ~Dragon() override = default;
    Dragon& operator=(const Dragon& other) = default;
};

#endif //CARD_H_DRAGON_H
