#include "../Mtmchkin.h"
int main(){
    const int MAX_ROUNDS = 100;
    Mtmchkin game("deck.txt");
    while (!game.isGameOver() && game.getNumberOfRounds() < MAX_ROUNDS){
        game.playRound();
    }
    game.printLeaderBoard();
    return 0;
}