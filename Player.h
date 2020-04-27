
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

class Player
{
    private:
        string name;
        int currentHandValue;
        int currentAmountOfCards;
        int totalChipCount;
        Card* currentHand[11];      /*The array is set to 11 because in the worst case scenario, 
                                    the max amount of cards a player  can have without loosing is 11   */
    public:
        void addCard(Card * cardAdded);
        void clearHand();
        int getCurrentHandValue();
        string getName();
        void printHand();
        int calculateBestScore();
        void updateChipWin(int chipsWon);
        void updateChipLost(int chipsLost);
        int getTotalChipCount();
        Player(string name);
};



#endif /* PLAYER_H */

