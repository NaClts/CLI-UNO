// display_waitingForAI.h

#include <iostream>
#include <string>
#include <unistd.h>     // For the calling of sleep()
#include "selfDefStruct.h"  // For the calling of self-defined structures (UNO, playedUNO, listOfCards)
#include "display_waitingForAI.h"    // Allow other programs to call this function via the header file
using namespace std;

void display_waitingForAI(playedUNO currentCard, int AIIndex, ListOfCards user[], int numOfPlayers) {

    system("clear");

    //1 Print the number of AI and which AI is playing on the top 
    cout << "Current player :" << endl;
    cout << "You";
    for ( int i = 2 ; i < numOfPlayers + 1 ; i++ ) {
        if ( (AIIndex + 1) == i )
            cout << " \033[1;32;40m[AI" << i << "]\033[0m";
        else
            cout << " AI" << i;
    }
    cout << endl << endl;

    //2 Display the latest discard
    cout << "Latest discard :" <<endl;
    if ( currentCard.card.col == 'n' ) {
        if ( currentCard.colourToChange == 'b' )
            cout << "\033[1;40;34m";
        else if ( currentCard.colourToChange == 'g' )
            cout << "\033[1;40;32m";
        else if ( currentCard.colourToChange == 'r' )
            cout << "\033[1;40;31m";
        else if ( currentCard.colourToChange == 'y' )
            cout << "\033[1;40;33m";
    }
    else if ( currentCard.card.col == 'b')
        cout << "\033[1;44;37m";
    else if ( currentCard.card.col == 'g')
        cout << "\033[1;42;30m";
    else if ( currentCard.card.col == 'r')
        cout << "\033[1;41;37m";
    else if ( currentCard.card.col == 'y')
        cout << "\033[1;43;30m";
    cout << "┌───────┐" << endl;
    cout << "│       │" << endl;
    cout << "│";
    if ( currentCard.card.num >= '0' && currentCard.card.num <= '9' )
        cout << "   " << currentCard.card.num << "   ";
    else if ( currentCard.card.col == 'n' && currentCard.card.num == 'D')
        cout << " Draw 4";
    else if ( currentCard.card.num == 'W')
        cout << "  Wild ";
    else if ( currentCard.card.num == 'D')
        cout << " Draw 2";
    else if ( currentCard.card.num == 'R')
        cout << "Reverse";
    else if ( currentCard.card.num == 'S')
        cout << "  Skip ";
    cout << "│" << endl;
    cout << "│       │" << endl;
    cout << "└───────┘" << "\033[0m" << endl << endl;

    //3 Display the instruction and meanings of notations
    cout << "(D = Draw 2 (Draw 4 if it is white/black))" << endl;
    cout << "(W = Wild)" << endl;
    cout << "(R = Reverse)" << endl;
    cout << "(S = Skip)" << endl;

    //4 Print the cards that are held by the player currently
    cout << "Your cards :" << endl;
    int n = 0;  // Total no. of cards
    int i = 0;
    UNO cardRead = user[0].card[i];
    while ( i < 100 ) {
        if ( cardRead.col ) {
            if ( cardRead.col == 'b')
                cout << "\033[1;34m";
            else if ( cardRead.col == 'g')
                cout << "\033[1;32m";
            else if ( cardRead.col == 'r')
                cout << "\033[1;31m";
            else if ( cardRead.col == 'y')
                cout << "\033[1;33m";
            cout << user[0].card[i].num << " " << "\033[0m" ;
            n++;
        }
        i++;
        cardRead = user[0].card[i];
    }
    cout << endl;

    sleep(2);

    return;
}