#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"

class Card {
public:
    Card(const std::string name);
    virtual void applyEncounter(Player& player) const = 0;
    virtual void printInfo(std::ostream& os) const;
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

protected:
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    std::string m_name;
};

#endif
