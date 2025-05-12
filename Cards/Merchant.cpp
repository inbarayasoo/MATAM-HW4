#include "Merchant.h"
#include <iostream>
#include <string>
#include "../utilities.h"

using namespace std;

static bool inputOnlyWithNumbers(string input) {
    if (input.size() != 1) {
        return false;
    }
    if(!(input.compare("0")) || !(input.compare("1")) || !(input.compare("2"))) {
        return true;
    }
    return false;
}

void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getPlayerName(), player.getPlayerCoins());
    string input;
    int paid = 0, correctInput;
    bool correctNumber = false;
    do {
        getline(cin,input);
        if((inputOnlyWithNumbers(input))) {
            correctInput = stoi(input);
            correctNumber = true;
        }
        else {
            printInvalidInput();
        }
    } while(!correctNumber);
    if(correctInput == PLAYER_CHOOSE_HEAL) {
        if(player.pay(COINS_FOR_HEAL)) {
            paid = COINS_FOR_HEAL;
            player.heal(BUY_ONE_HEAL);
        }
        else {
            printMerchantInsufficientCoins(cout);
        }
    }
    if(correctInput == PLAYER_CHOOSE_FORCE) {
        if(player.pay(COINS_FOR_FORCE)) {
            paid = COINS_FOR_FORCE;
            player.buff(BUY_ONE_FORCE);
        }
        else {
            printMerchantInsufficientCoins(cout);
        }
    }
    printMerchantSummary(cout,player.getPlayerName(), correctInput,paid);

}
Merchant::Merchant() : Card("Merchant") {}
