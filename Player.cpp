
#include "Player.h"

void Player :: addCard(Card * cardAdded)
{
    if (currentAmountOfCards == 11)
    {
        cout << "Error" << endl;
    }
    
    currentHand[currentAmountOfCards] = cardAdded;
    currentAmountOfCards++;
    return;
}

int Player:: calculateBestScore()
{
    int numberOfAces = 0;
    int bestScore = 0;
    for (int i = 0; i < currentAmountOfCards; i++)
    {
        if (currentHand[i]->getValue() == -1)
        {
            numberOfAces++;
        }
        else
        {
            bestScore+= currentHand[i]->getValue();
        }
    }
    
    for (int i = 0; i < numberOfAces; i++)
    {
        if(numberOfAces > 1 || bestScore + 11 > 21)
        {
            bestScore+=1;
            numberOfAces -= 1;
        }
        else 
        {
            bestScore += 11;
            numberOfAces -= 1;
        }
    }
    return bestScore;
}

void Player :: clearHand()
{
    for (int i = 0; i < 11; i++)
    {
        currentHand[i] = 0;
    }
    
    currentAmountOfCards = 0;
    
    return;
}

int Player :: getCurrentHandValue()
{
    return currentHandValue;   
}

string Player :: getName()
{
    return name;
}

Player::Player(string name)
{
    this->name = name;
    currentHandValue = 0;
    totalChipCount = 100;
    currentAmountOfCards = 0;
}

void Player:: printHand()
{
    for (int i = 0; i < currentAmountOfCards; i++)
    {
        currentHand[i]->printCard();
    }
}
void Player:: updateChipWin(int chipsWon)
{
    totalChipCount+= chipsWon;
}
void Player::  updateChipLost(int chipsLost)
{
    if(totalChipCount - chipsLost >= 0)
    {
        totalChipCount -= chipsLost;
    }
    else
    {
        cout << "ERROR, chips lost > chips currently owned" << endl;
    }
    return;
}
int Player:: getTotalChipCount()
{
    return totalChipCount;
}
