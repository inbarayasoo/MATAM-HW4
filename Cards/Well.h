#ifndef CARD_H_PITFALL_H
#define CARD_H_PITFALL_H

#include "Card.h"
#include "../Players/Ninja.h"

const int DAMAGE_BY_WELL = 10;

class Well : public Card {
public:
        Well();
        Well(const Well&) = default;
        ~Well() = default;
        Well& operator=(const Well& other) = default;
        void applyEncounter(Player& player) const override;
};

#endif //CARD_H_PITFALL_H
