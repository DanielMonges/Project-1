#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include <stack>
#include "Card.h"
#include "Player.h"
#include "Event.h"

using namespace std;

void shuffleDeck(Card ** cardArray);
void selectCard(Player & player, Card ** cardArray);
bool botSelection(Player & enemy);
void printInstructions();
int returnBetAmount(Player & user, Player & enemy);
void printGameHistory(list<Event> history);

int main(int argc, char** argv) {

    srand(0);
    string answer;
    cout << "                         ---------------------" << endl;
    cout << "                         Welcome To BlackJack!" << endl;
    cout << "                         ---------------------" << endl << endl;
    cout << " ----------------------------------------------------------------------" << endl;
    cout << " The Card Game In Which You Must Get As Close To 21 As Possible To Win!" << endl;
    cout << " ----------------------------------------------------------------------" << endl << endl;
    cout << "    ---------------------------------  ---------------------------" << endl;
    cout << "    To Play The Game Enter In Any Key  To Quit The Game Enter In q" << endl;
    cout << "    ---------------------------------  ---------------------------" << endl << endl;
    cin >> answer;
    cout << endl;

if (answer == "q")
{
    return 0;
}

if (answer != "q")
{
    
    
    cout << "Would you like to view the instructions how to play?" << endl;
    cout << "Select y/n: ";
    cin >> answer;
    
    while (answer != "n" && answer != "y")
    {
        cout << "Incorrect input.  Answer 'y' or 'n'";
        cin >> answer;
    }
    if (answer == "y")
    {
        printInstructions();
    }
    
    Card* cardArray[52];
    string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int cardValue[13] = {-1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
    string suitNumber[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int Count = 0;
    int bet = 0;
    list<Event> gameHistory;
    stack<Card> cardStack;
    
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            cardArray[Count] = new Card(suits[i], cardValue[j], suitNumber[j]);
            Count++;
        }
    }
    
    cout << " -----------------------" << endl;
    cout << " Please Enter Your Name:" << endl;
    cout << " -----------------------" << endl << endl;    
    cin >> answer;
    cout << endl;
    
    Player user(answer);
    Player enemy("Bot Joe");
    
    cout << " -----------------------------------" << endl;
    cout << "          Welcome, " << user.getName() << ". " << endl;
    cout << " -----------------------------------" << endl << endl;    
    
    while( answer != "q")
    {
        cout << "--------------------------" << endl;
        cout << " Your chip count: " << user.getTotalChipCount() << endl;
        cout << enemy.getName() <<"'s chip count: " << enemy.getTotalChipCount() << endl;
        cout << "--------------------------" << endl << endl;
        cout << " -------------------------------------------------- " << endl;
        cout << " To start another round, select 'c', or 'h' to view the history, or select 'q' to quit: " << endl;
        cout << " -------------------------------------------------- " << endl << endl;
        cin >> answer;
        
        while(answer != "q" && answer != "c"  && answer != "h")
        {
            cout << " --------------------------------------------------------- " << endl;
            cout << " Invalid choice, please select 'd', or select 'q' to quit: " << endl;
            cout << " --------------------------------------------------------- " << endl << endl;
            cin >> answer;
        }
        
        if (answer == "q")
        {
            break;
        }
        
        if (answer == "h"){
            printGameHistory(gameHistory);
        }
        
        
        cout << " ---------------" << endl;
        cout << " Beginning Round" << endl;
        cout << " ---------------" << endl << endl;        
        
        
        cout << "Shuffling Deck" << endl;
        shuffleDeck(cardArray);
        
        
        
        bet = returnBetAmount(user,enemy);
        
        cout <<" Player 1 drawing card:" << endl;
        selectCard(user, cardArray);
        cout << " Current Hand:" << endl;
        user.printHand();
        cout << " Current Score: " << user.calculateBestScore() << endl;
        
        cout << " Type anything to continue: ";
        cin >> answer;
        
        cout << " -------------------------" << endl;
        cout << enemy.getName() << " is drawing a card." << endl;
        selectCard(enemy, cardArray);
                
        cout << " Type anything to continue: " << endl;
        cin >> answer;
        
        
        cout <<"Player 1 drawing card:" << endl;
        selectCard(user, cardArray);
        cout << "Current Hand:" << endl;
        user.printHand();
        cout << "Current Score: " << user.calculateBestScore() << endl;
        
        cout << "Type anything to continue: ";
        cin >> answer;
        
        cout << " --------------------------" << endl;
        cout << enemy.getName() << " is drawing a card." << endl;
        selectCard(enemy, cardArray);
        cout << " --------------------------" << endl;
        
         bool botChoice = true;
        
        while(user.calculateBestScore() < 21 && (answer != "stay" || botChoice))
        {
           
            if (answer!= "stay")
            {
                
                cout << " Your current score is " << user.calculateBestScore() << endl;
                cout << " Do you want to hit or stay?" << endl;
                cout << " Type 'hit' or 'stay'" << endl;
                cin >> answer;
            }
            
           
            while (answer != "hit" && answer != "stay")
            {
                cout << " fInvalid choice, select 'hit' or 'stay'" << endl;
                cin >> answer;
            }
            
            if (answer == "hit")
            {
                cout << " Drawing new card" << endl;
                selectCard(user, cardArray);
                user.printHand();
                cout << " Current Score: " << user.calculateBestScore() << endl;
            }
            
            if (botChoice != false) 
            {
                botChoice = botSelection(enemy);
            }
            
            if(botChoice)
            {
                cout<< enemy.getName() << " is choosing to hit." << endl;
                selectCard(enemy, cardArray);
                cout << enemy.getName() << " drew a card." << endl;
            }
            else if(enemy.calculateBestScore() <= 21)
            {
                
                cout << enemy.getName() << " decided to stay." << endl << endl << endl; 
             
            }
        }
        
        cout << endl << endl;
        int finalScoreUser = user.calculateBestScore();
        int finalScoreEnemy = enemy.calculateBestScore();
        
        cout << "The player " << user.getName() << " has score: " << finalScoreUser << endl;
        cout << enemy.getName() << " has score: " << finalScoreEnemy << endl;
        
        
        if (finalScoreUser > 21 && finalScoreEnemy > 21){
            cout << "---------------------------------------------" << endl;
            cout << "Draw.  Both players have score over 21." << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Player " << user.getName() << " has " << user.getTotalChipCount() << " chips" << endl;
            cout << enemy.getName() << " has " << enemy.getTotalChipCount() << " chips" << endl;  
            gameHistory.push_back(Event(user, enemy, bet, 0, true));
        }
        
        if (finalScoreUser > 21 && finalScoreEnemy <= 21){
            cout << " The player " << user.getName() << " has score over 21" << endl;
            cout << "----------------------------------------------" << endl;
            cout << " The winner of this round is" << enemy.getName() << endl;
            cout << "----------------------------------------------" << endl;
            enemy.updateChipWin(bet);
            user.updateChipLost(bet);
            cout << "New Chip amounts: " << endl;
            cout << "Player " << user.getName() << " has " << user.getTotalChipCount() << " chips" << endl;
            cout << enemy.getName() << " has " << enemy.getTotalChipCount() << " chips" << endl;
            gameHistory.push_back(Event(user, enemy,bet, 0, false));
        }
        
        else if (finalScoreUser <= 21 && finalScoreEnemy > 21){
            cout << enemy.getName() << " has score over 21" << endl;
            cout << " ---------------------------------------------" << endl;
            cout << " The winner of this round is the player " << user.getName() << endl;
            cout << " ---------------------------------------------" << endl;
            user.updateChipWin(bet);
            enemy.updateChipLost(bet);
            cout << "New Chip amounts: " << endl;
            cout << "Player " << user.getName() << " has " << user.getTotalChipCount() << " chips" << endl;
            cout << enemy.getName() << " has " << enemy.getTotalChipCount() << " chips" << endl;
            gameHistory.push_back(Event(user, enemy, bet, 1, false));
        }
        
        else if (finalScoreUser <= 21 && finalScoreEnemy > 21){
            cout << " ---------------------------------------------" << endl;
            cout << "The winner of this round is"  << enemy.getName() << endl;
            cout << " ---------------------------------------------" << endl;
            enemy.updateChipWin(bet);
            user.updateChipLost(bet);
            cout << "New Chip amounts: " << endl;
            cout << "Player " << user.getName() << " has " << user.getTotalChipCount() << " chips" << endl;
            cout << enemy.getName() << " has " << enemy.getTotalChipCount() << " chips" << endl;
            gameHistory.push_back(Event(user, enemy, bet, 0, false));
        }
        
        else {
            
            int userDistanceFrom21 = abs(21 - finalScoreUser);
            int enemyDistanceFrom21 = abs(21 - finalScoreEnemy);
            
            if (userDistanceFrom21 < enemyDistanceFrom21){
                cout << "-----------------------------" << endl;
                cout << user.getName() << " is the winner" << endl;
                cout << "-----------------------------" << endl;
                user.updateChipWin(bet);
                enemy.updateChipLost(bet);
                cout << "New Chip amounts: " << endl;
                cout << "Player " << user.getName() << " has " << user.getTotalChipCount() << " chips" << endl;
                cout << enemy.getName() << " has " << enemy.getTotalChipCount() << " chips" << endl;
                gameHistory.push_back(Event(user, enemy, bet, 1, false));
            }
            
            else if (userDistanceFrom21 > enemyDistanceFrom21){
                cout << "-----------------------------" << endl;
                cout << enemy.getName() << " is the winner"<< endl;
                cout << "-----------------------------" << endl;
                enemy.updateChipWin(bet);
                user.updateChipLost(bet);
                cout << "New Chip amounts: " << endl;
                cout << "Player " << user.getName() << " has " << user.getTotalChipCount() << " chips" << endl;
                cout << enemy.getName() << " has " << enemy.getTotalChipCount() << " chips" << endl;
                gameHistory.push_back(Event(user, enemy, bet, 0, false));
                
            }
            
            else if (userDistanceFrom21 == enemyDistanceFrom21)
            {
                cout << "-----------------------------" << endl;
                cout <<"Draw.  Both players have the same score" << endl;
                cout << "-----------------------------" << endl;
                cout << "Player " << user.getName() << " has " << user.getTotalChipCount() << " chips" << endl;
                cout << enemy.getName() << " has " << enemy.getTotalChipCount() << " chips" << endl;
                gameHistory.push_back(Event(user, enemy, bet, 0, true));
            }
        }
        
        user.clearHand();
        enemy.clearHand();
        
        for (int i = 0; i < 52; i++){
            cardArray[i]->setNotTaken();
        }
        
        if (user.getTotalChipCount() == 0 || enemy.getTotalChipCount() == 0)
        {
            if (user.getTotalChipCount() > enemy.getTotalChipCount())
            {
                cout<< "The player " << user.getName() << " has won the tournament" << endl;
            }
            
            else {
                cout<< enemy.getName() << " has won the tournament" << endl;
            }
            break;
        }
        cout << "                        -----------------------------" << endl;
        cout << "                        Would You Like To Play Again?" << endl;
        cout << "                        -----------------------------" << endl << endl;
      
        
        
    }
    
    cout << "Thank you for playing! " << endl;
    
}
    return 0;
}

void selectCard(Player & currPlayer, Card** cardArray)
{
    
    int randomCard = rand() % 52;
    while(cardArray[randomCard]->checkTaken())
    {
        randomCard = rand() % 52;
    }
    
    currPlayer.addCard(cardArray[randomCard]);
    cardArray[randomCard]->setTaken();
    return;
    
}

bool botSelection(Player & enemy)
    {
    int choice = false;
    if(enemy.calculateBestScore() < 10){
        return true;
    }

    else if(enemy.calculateBestScore() >  10 && enemy.calculateBestScore() <= 16){
        choice = rand()%2;
        if(choice) 
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
   
}

void printInstructions()
{
    cout << " -------------" << endl;
    cout << " How To Play: " << endl; 
    cout << " -------------" << endl << endl;
    cout << " The goal of the game is to have the hand that has a value of 21 or has the closest value to 21." << endl;
    cout << " The game is played with one or more 52 standard decks, however in this case the game will be played with only 1 deck." << endl;
    cout << " If your hand value is over 21 causes you to bust, and you will lose regardless of the other player's hand." << endl;
    cout << " Aces have a value of 1 or 11." << endl;
    cout << " Cards 2-9 all have their designated number as their value." << endl;
    cout << " 10s, Jacks, Queens, and Kings all have a value of 10." << endl;
    cout << " A blackjack is the most powerful hand, consisting of an Ace and any card that has a value of 10." << endl;
    cout << " Each player is given 2 cards before anything is done." << endl;
    cout << " There are 3 different choices the player can make after the cards has been dealt: Hit, Stay, or Double Down." << endl;
    cout << " Hit: When you ask for another card, you can keep doing this till you are satisfied or till you bust." << endl;
    cout << " Stay: When you stay with your current hand and don't take in any extra cards." << endl;
    cout << " Double Down: When you double your bet and you take only 1 extra card." << endl;
}

int returnBetAmount(Player & user, Player & enemy)
{
    cout << "You currently have " << user.getTotalChipCount() << " chips." << endl;
    cout << enemy.getName() << " currently has " << enemy.getTotalChipCount() << endl;
    cout << "Enter your bid amount.  Minimum 10 chips and must be divisible by 10: " << endl << endl;
    int ans;
    cin >> ans;
    
    while ((ans >= 0 && ans < 10) || (ans > user.getTotalChipCount()) || (ans > enemy.getTotalChipCount()) || (ans %10) )
    {
        cout << "INVALID CHIP AMOUNT." << endl;
        if(ans >= 0 && ans < 10)
        {
            cout << "Bet too low, minimum bet is 10 chips.  Enter valid chip amount: " << endl;
            cin >> ans;
        }
        else if(ans > user.getTotalChipCount())
        {
            cout << "Bet too high. You only have " << user.getTotalChipCount() << " chips. Enter valid chip amount: " << endl;
            cin >> ans;
        }
        else if(ans > enemy.getTotalChipCount())
        {
            cout << "Bet too high. " << enemy.getName() << " only has " << user.getTotalChipCount() << " chips. Enter valid chip amount: " << endl;
            cin >> ans;
        }
        else if (ans %10){
            cout << "Bet must be divisible by 10.  Enter valid chip amount: " << endl;
            cin >> ans;
        }
    }
   
    cout << "Betting " << ans << " chips." << endl;
    return ans;
    
    
}

void printGameHistory(list<Event> history)
{
     cout << endl << endl;
    cout << "-----------------------------" << endl;
    cout << "       Game History          " << endl;
    cout << "-----------------------------" << endl << endl << endl; 
    
    if (history.begin() == history.end()){
        cout << "No game history, go play a game!" << endl << endl << endl ;
        return;
    }
    int eventTag = 1;
   
     
    for(list<Event>::iterator it = history.begin(); it != history.end(); it++){
        cout << eventTag << "." << endl;
        
        if (it->getDraw()){
           cout << "Round Draw, no winner." ;
        }
        else
        {
            cout << "Winner of round: " << it->getRoundWinner() << endl;
            cout << "Winnings:  "<< it->getRoundWinnings() << endl;
            cout << "User's hand score: " << it->getUserScore() << endl;
            cout << "Enemy's hand score: " << it->getEnemyScore() << endl;
        }
        
        cout << endl << endl << endl;
        eventTag++;
    }
    
    
}

void shuffleDeck(Card ** cardArray)
{
    Card * randomizedCards[52];
    copy(cardArray, cardArray + 52, randomizedCards);
    random_shuffle(randomizedCards, randomizedCards + 52);
    stack<Card*> cardStack;
    
    for(int i = 0; i < 52; i++){
        cardStack.push(randomizedCards[i]);
    }
    
    for (int i = 0; i < 52; i++){
        cardArray[i] = cardStack.top();
        cardStack.pop();
    }
    
}

