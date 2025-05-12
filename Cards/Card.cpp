#include "Card.h"
#include "../utilities.h"

using namespace std;

Card::Card(const string name) : m_name(name) {}

ostream& operator<<(ostream& os, const Card& card)
{
    card.printInfo(os);
    return os;
}

void Card::printInfo(ostream& os) const
{
    printCardDetails(os,this->m_name);
    printEndOfCardDetails(os);
}