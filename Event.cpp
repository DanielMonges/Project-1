#include "Event.h"

using namespace std;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

string Event:: getRoundWinner()
{
    return roundWinner;
}

int Event:: getRoundWinnings()
{
    return roundWinnings;
}
int Event:: getUserScore()
{
    return userScore;
}
int Event:: getEnemyScore()
{
    return enemyScore;
}

bool Event :: getDraw()
{
    return draw;
}

Event:: Event(Player user, Player enemy, int winnings, int whoWon, bool draw)
{
    if (draw)
    {
        this->draw = draw;
    }
    
    else if(whoWon)
    {
        roundWinner = user.getName();
    }
    else 
    {
        roundWinner = enemy.getName();
    }
    
    userScore = user.calculateBestScore();
    enemyScore = enemy.calculateBestScore();
    roundWinnings = winnings;
    
    return;
}