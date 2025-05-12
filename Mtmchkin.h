#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Cards/Card.h"
#include "Players/Player.h"
#include <deque>
#include <iostream>
#include <memory>

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string& fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    bool checkValidNameCardAndPush(const std::string& nameOfCard);

    void JobPush(const std::string& playerName,const std::string& playerJob);

    void getPlayer(int numberOfPlayers);

    static int getTeamSize();

    bool addWitch();
    bool addGremlin();
    bool addDragon();
    bool addTreasure();
    bool addMana();
    bool addMerchant();
    bool addWell();
    bool addBarfight();
    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin&) = delete;
    ~Mtmchkin() = default;

private:
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Card>> m_cards;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    int m_numberOfRounds;
};



#endif /* MTMCHKIN_H_ */
