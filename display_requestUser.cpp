// display_requestUser.cpp

#include <iostream>
#include <string>
#include <fstream>  // For file input/output
#include "SaveAndLoad.cpp"  // Include the file where saveGameProgress and loadGameProgress are defined
#include <cstdlib>  // For calling srand(), rand()
#include <ctime>    // For calling time()
#include "selfDefStruct.h"  // For the calling of self-defined structures (UNO, playedUNO, listOfCards)
#include "random.h" // For calling randomSingleUNO()
#include "display_requestUser.h"    // Allow other programs to call this function via the header file
using namespace std;

playedUNO display_requestUser( ListOfCards user[] , playedUNO currentCard , int numOfPlayer ) {

    system("clear");

    //1 Print the number of AI on the top 
    cout << "Current player :" << endl;
    cout << "\033[1;32;40m[YOU]\033[0m";
    for (int i = 2 ; i < (numOfPlayer + 1) ; i++ ) {
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
    cout << endl << endl;

    cout << "Please enter the colour of the card following by the NUMBER/ACTION" << endl;
    cout << "For example: yD (Yellow Draw 2), nW (Wild), nD (Draw 4)" << endl;
    cout << "If you want to draw extra card, enter DRAW" << endl;
    cout << "If you want to save and exit the game, enter 'wq'" << endl；

    //5 Checking whether the card to be inputed by player is valid
    //    If not, the user will be asked again
    bool valid, cardExist, draw = false;
    string userInput;
    char col, num, colToChange;
    while ( !valid ) {
        cout << "Which card would you like to play? ";
        cin >> userInput;

        //EXCEPTION: If user hopes to draw a new card, the loop is exited
        if ( userInput == "DRAW" ) {
            draw = true;
            break;
        }
        
        col = userInput.c_str()[0];
        num = userInput.c_str()[1];
        i = 0;  // Defined earlier
        cardRead = user[0].card[i];     // Defined earlier

        //5.1 Check whether the card is in the user card list
        cardExist = false;
        while ( i < 100 && !cardExist) {
            if ( col == cardRead.col && num == cardRead.num )
                cardExist = true;
            else
                i++;
                cardRead = user[0].card[i];
        }

        //5.2 If the card is found...
        if ( cardExist ) {
            //5.2.1 If the card is of no colour, ask for the colour to change
            if ( col == 'n' ) {
                bool colourValid = false;
                while ( !colourValid ) {    // Ask the colour to change until user gives a valid input
                    cout << "Which colour would you like to change (b/g/r/y)? ";
                    cin >> userInput;
                    colToChange = userInput.c_str()[0];
                    if ( colToChange == 'b' || colToChange == 'g' || colToChange == 'r' || colToChange == 'y' ) {
                        colourValid = true;
                        valid = true;
                    }
                    else
                        cout << "Invalid colour!" << endl;
                }
            }

            //5.2.2 If the card is b/g/r/y, check whether it matches the current discard 
            else {
                if ( col == currentCard.card.col || col == currentCard.colourToChange || num == currentCard.card.num ) {
                    colToChange = 'n';
                    valid = true;
                }
                else
                    cout << "Mismatch card!" << endl;
            }
        }

        //5.3 If the card is not found
        else
            cout << "Card not found!" << endl;
    }

    // Initialize the card to be returned
    playedUNO newCard;

    if ( draw ) {
        // The round is skipped and the current discard remains
        newCard = currentCard;
        
        // Draw a new card
        UNO newDraw = randomSingleUNO(time(NULL) - 246810);
        
        if ( n == 100 ) {
            // Replace a random card if the total card number = 100
            srand(time(NULL)-12345678);
            user[0].card[ rand() % 100 ] = newDraw;
        }
        else {
            // Add a new random card if the total card number < 100
            for ( int k = 0 ; k < 100 ; k++ ) {
                if ( !user[0].card[k].col ) {
                    user[0].card[k] = newDraw;
                    break;
                }
            }
        }
    }
    else {
        // Put the cards to the front and replace the played card
        while ( user[0].card[i+1].col ) {
            user[0].card[i] = user[0].card[i+1];
            i++;
        }

        // Delete the newly played card from the card list
        user[0].card[i].col = '\0';
        user[0].card[i].num = '\0';
        
        // Returning the newly played card
        newCard.card.col = col;
        newCard.card.num = num;
        newCard.colourToChange = colToChange;
    }

    return newCard;
}
