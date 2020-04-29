    #include <iostream>
#include "Card.h"

string Card :: getSuit()
{
    return suit;
}

int Card :: getValue()
{
    return value;
}

void Card :: setTaken()
{
    taken = 1;
}

void Card :: setNotTaken()
{
    taken = 0;
}

bool Card :: checkTaken()
{
    return taken;
}

string Card :: getsuitNumber()
{
    
    return suitNumber;
}

Card :: Card(string x, int y, string z)
{
    
    suit = x;
    value = y;
    suitNumber = z;
    taken = 0;
}

void Card:: printCard()
{
    cout << "-------------------------" << endl;
    cout << "  " << getsuitNumber() << "                    " << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "       " << getSuit() << "          " << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|                    " << getsuitNumber() << "" << endl;
    cout << "-------------------------" << endl;
}

