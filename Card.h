#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card
{    
private: 
    string suit;
    int value;
    string suitNumber;
    bool taken;
public:
    string getSuit();
    int getValue();
    string getsuitNumber();
    void setTaken();
    void setNotTaken();
    bool checkTaken();
    void printCard();
    Card(string x, int y, string z);
            
};

#endif /* CARD_H */

