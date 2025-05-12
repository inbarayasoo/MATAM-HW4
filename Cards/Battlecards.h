#ifndef BARFIGHT_H_BATTLECARDS_H
#define BARFIGHT_H_BATTLECARDS_H

#include "Card.h"

class Battlecards : public Card {
public:
    Battlecards(const std::string name , int force , int loot , int hpLossOnDefeat);
    Battlecards(const Battlecards&) = default;
    ~Battlecards() override = default;
    Battlecards& operator=(const Battlecards& other) = default;
    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream& os) const override;

protected:
    int m_force;
    int m_loot;
    int m_hpLossOnDefeat;

};

#endif //BARFIGHT_H_BATTLECARDS_H
