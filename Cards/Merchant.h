#ifndef CARD_H_MERCHANT_H
#define CARD_H_MERCHANT_H

#include "Card.h"

int const BUY_ONE_HEAL = 1;
int const BUY_ONE_FORCE = 1;
int const ERROR_INPUT = 2;
int const COINS_FOR_HEAL = 5;
int const COINS_FOR_FORCE = 10;
int const PLAYER_CHOOSE_HEAL = 1;
int const PLAYER_CHOOSE_FORCE = 2;

class Merchant : public Card {
public:
    Merchant();
    Merchant(const Merchant&) = default;
    ~Merchant() override = default;
    Merchant& operator=(const Merchant& other) = default;
    void applyEncounter(Player& player) const override;
};
#endif //CARD_H_MERCHANT_H
