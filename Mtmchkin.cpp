#include<fstream>
#include <string>

#include "Mtmchkin.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Exception.h"
#include "utilities.h"

#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Witch.h"

using std::cout;
using std::ifstream;
using std::getline;
using std::stoi;
using std::move;
using std::unique_ptr;
using std::string;
using std::cin;

const int FIRST_PLACE = 1;
const int MIN_SIZE_CARD = 5;
const int MAX_NAME_LENGTH = 15;
const char MIN_LOWERCASE = 'a';
const char MAX_LOWERCASE = 'z';
const char MIN_UPPERCASE = 'A';
const char MAX_UPPERCASE = 'Z';
const string HEALER_JOB = "Healer";
const string WARRIOR_JOB = "Warrior";
const string NINJA_JOB ="Ninja";

static bool isValidName(const string& playerName) {
    if (playerName.length() <= 0 || playerName.length() > MAX_NAME_LENGTH) {
        return false;
    }
    for (unsigned int index = 0; index < playerName.length(); index++) {
        char letterAtIndex = playerName[index];
        if (!(letterAtIndex >= MIN_UPPERCASE && letterAtIndex <= MAX_UPPERCASE) &&
            !(letterAtIndex >= MIN_LOWERCASE && letterAtIndex <= MAX_LOWERCASE)) {
            return false;
        }
    }
    return true;
}

static bool isValidJob(const string& playerJob) {
    if (playerJob == HEALER_JOB) {
        return true;
    } else if (playerJob == WARRIOR_JOB) {
        return true;
    } else if (playerJob == NINJA_JOB) {
        return true;
    }
    return false;
}

static bool inputSizeOnlyWithNumbers(const string& teamSize)
{
    if (teamSize.size() != 1) {
        return false;
    }
    if(!(teamSize.compare("2")) || !(teamSize.compare("3")) ||
    !(teamSize.compare("4")) || !(teamSize.compare("5")) || !(teamSize.compare("6"))) {
        return true;
    }
    return false;
}

void Mtmchkin::getPlayer(int numberOfPlayers)
{
    string playerName;
    string playerJob;
    for (int i = 0; i < numberOfPlayers; i++) {
        printInsertPlayerMessage();
        getline(cin, playerName, ' ');
        getline(cin, playerJob);
        while (!isValidName(playerName) || !isValidJob(playerJob)) {
            if (!isValidName(playerName))
            {
                printInvalidName();
            }
            else
            {
                printInvalidClass();
            }
            getline(cin, playerName, ' ');
            getline(cin, playerJob);
        }
        JobPush(playerName,playerJob);
    }
}

int Mtmchkin::getTeamSize()
{
    int numberOfPlayers;
    string teamSize;
    bool validSize = false;
    while (!validSize)
    {
        printEnterTeamSizeMessage();
        getline(cin, teamSize);
        if (inputSizeOnlyWithNumbers(teamSize))
        {
            numberOfPlayers = stoi(teamSize);
            validSize = true;
        }
        else
        {
            printInvalidTeamSize();
        }
    }
    return numberOfPlayers;
}

Mtmchkin::Mtmchkin(const std::string& fileName) : m_numberOfRounds(0) {
    printStartGameMessage();
    ifstream source(fileName);
    if (!source)
    {
        throw DeckFileNotFound();
    }
    string nameOfCard;
    int lineOfError = 0;
    while (getline(source, nameOfCard)) {
        ++lineOfError;
        if (checkValidNameCardAndPush(nameOfCard))
        {
            continue;
        }
        else
        {
            throw DeckFileFormatError(lineOfError);
        }
    }
    if (m_cards.size() < MIN_SIZE_CARD)
    {
        throw DeckFileInvalidSize();
    }

    int numberOfPlayers = getTeamSize();
    getPlayer(numberOfPlayers);
}

bool Mtmchkin::addWitch(){
    unique_ptr<Card> card(new Witch());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::addGremlin(){
    unique_ptr<Card> card(new Gremlin());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::addDragon(){
    unique_ptr<Card> card(new Dragon());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::addTreasure(){
    unique_ptr<Card> card(new Treasure());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::addMana(){
    unique_ptr<Card> card(new Mana());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::addMerchant(){
    unique_ptr<Card> card(new Merchant());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::addWell(){
    unique_ptr<Card> card(new Well());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::addBarfight(){
    unique_ptr<Card> card(new Barfight());
    m_cards.push_back(move(card));
    return true;
}

bool Mtmchkin::checkValidNameCardAndPush(const string& nameOfCard)
{
    if (nameOfCard == "Witch")
    {
        return addWitch();
    }
    else if (nameOfCard == "Gremlin")
    {
        return addGremlin();
    }
    else if (nameOfCard == "Dragon")
    {
        return addDragon();
    }
    else if (nameOfCard == "Treasure")
    {
        return addTreasure();
    }
    else if (nameOfCard == "Mana")
    {
        return addMana();
    }
    else if (nameOfCard == "Merchant")
    {
        return addMerchant();
    }
    else if (nameOfCard == "Well")
    {
        return addWell();
    }
    else if (nameOfCard == "Barfight")
    {
        return addBarfight();
    }
    return false;
}

void Mtmchkin::JobPush(const string& playerName, const string& playerJob)
{
    if (playerJob == WARRIOR_JOB)
    {
        unique_ptr<Player> player(new Warrior(playerName));
        m_players.push_back(move(player));
    }
    else if (playerJob == NINJA_JOB)
    {
        unique_ptr<Player> player(new Ninja(playerName));
        m_players.push_back(move(player));
    }
    else if (playerJob == HEALER_JOB)
    {
        unique_ptr<Player> player(new Healer(playerName));
        m_players.push_back(move(player));
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numberOfRounds;
}

void Mtmchkin::playRound() {
    int NumbersOfPlayers = m_players.size();
    printRoundStartMessage(m_numberOfRounds + 1);
    for (int i = 0; i < NumbersOfPlayers; i++) {
        printTurnStartMessage(m_players.front()->getPlayerName());
        m_cards.front()->applyEncounter(*(m_players.front()));
        unique_ptr<Card> currentCard = move(m_cards.front());
        m_cards.pop_front();
        m_cards.push_back(move(currentCard));
        if (m_players.front()->getLevel() == MAX_LEVEL) {
            m_winners.push_back(move(m_players.front()));
            m_players.pop_front();
        } else if (m_players.front()->isKnockedOut()) {
            m_losers.push_back(move(m_players.front()));
            m_players.pop_front();
        } else {
            unique_ptr<Player> currentPlayer = move(m_players.front());
            m_players.pop_front();
            m_players.push_back(move(currentPlayer));
        }
    }
    if (isGameOver()) {
        printGameEndMessage();
    }
    m_numberOfRounds++;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = FIRST_PLACE, sizeWinners = m_winners.size(),
            sizeLosers = m_losers.size(), sizePlayers = m_players.size();
    for (int i = 0; i < sizeWinners; i++) {
        printPlayerLeaderBoard(ranking, *(m_winners[i]));
        ranking++;
    }
    for (int i = 0; i < sizePlayers; i++) {
        printPlayerLeaderBoard(ranking, *(m_players[i]));
        ranking++;
    }
    for (int i = sizeLosers; i > 0; i--) {
        printPlayerLeaderBoard(ranking, *(m_losers[i - 1]));
        ranking++;
    }
}

bool Mtmchkin::isGameOver() const {
    if (m_players.empty()) {
        return true;
    }
    return false;
}
