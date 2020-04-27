/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: drave
 *
 * Created on April 26, 2020, 2:32 PM
 */

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "Player.h"

using namespace std;

class Event{
private:
    string roundWinner;
    int roundWinnings;
    int userScore;
    int enemyScore;
    bool draw;
    
public:
    string getRoundWinner();
    int getRoundWinnings();
    int getUserScore();
    int getEnemyScore();
    bool getDraw();
    Event(Player user, Player enemy, int winnings, int whoWon, bool draw);
};


#endif /* EVENT_H */

