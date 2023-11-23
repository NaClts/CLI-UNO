// main.cpp

#include <iostream>
#include <cstdlib>  // For calling srand(), rand()
#include <ctime>    // For calling time()
#include "WelcomeScreen.h"
#include "initialcard.h"
using namespace std;

// Defining new type of variable "UNO"
// For example,
// ( UNO.col == 'n' && UNO.num == 'D' ) is Draw 4
// ( UNO.col == 'b' && UNO.num == '7' ) is Blue 7
struct UNO {
    char col;   // Colour of UNO card ( 'b' , 'g' , 'r' , 'y' , 'n' )
    char num;    // Number of UNO card ( '0'-'9', 'D'(Draw), 'R'(Reverse), 'S'(Skip) )
};

int main() {

    // Display the welcome screen and ask user to choose the game mode (i.e. the number of player)
    // Return the number of player (MAX: 10)
    int numOfPlayer = display_welcomeScreen();

    // Display and ask the user for the desired number of cards at the beginning of the game
    // Maximum 100
    int initialNumOfCards = display_initialNumOfCards();

    // Define a structure to store all the cards of a player
    struct ListOfCards {
        UNO card[100];      // Maximum number of cards can be owned by a player is 100
    };

    // Maxiumun number of players is 10
    ListOfCards player[10];

    // Randomly assign initial UNO cards to all players
    for (int i=0, i<numOfAI, i++) {
        for (int j=0; j<initialNumOfCards; j++)
            player[i].card[j] = randomSingleUNO( time(NULL) + j );
    }

    bool reverse = false;   // For reverse card - true if reverse card is played
    int counter = 0;        // The remainder of counter / numOfPlayer telling which player is going to play
    int round = 0;          // For the leaderboard

    // Stores the latest played card as "currentCard"
    struct playedUNO {
        UNO card;
        char colourToChange;    // Unless the latest card is "Wild" or "nD (Draw 4)", this should be set to 'n' (N/A)
    }
    playedUNO currentCard;

    // Initialize the starting card
    currentCard.card = randomSingleUNO( time(NULL) - 123456 );
    currentCard.colourToChange = 'n';

    // Each loop asks a player (user or AI) to play a suitable card, then determine and execute the action of the played card
    // Exit the loop when one of the player played all of his/her cards
    // If the number of cards holding by a player exceeds 100,
    // => the player can still draw a card,
    // => but a random card will be discarded automatically.
    while( !onePlayerNoCards(player) ) {

        // Ask for input of playing card from user or AI
        if ( counter % numOfPlayer == 0 )    // The turn of user
            currentCard = display_requestUser(player[0], currentCard);    // The card played by player is stored as "currentCard"
        else
            AIIndex = counter % numOfPlayer    // The turn of AI
            display_waitingForAI(currentCard, AIIndex, player[0]);     // Display which AI is playing and wait for a time delay of 1 second
            currentCard = AI_requestAI(player[AIIndex], currentCard);  // The card played by AI is stored as "currentCard"
        
        ///////////////////////////////////////////
        // (TO BE FILLED) Action after each cards//
        ///////////////////////////////////////////

        // Store the current game if user typed "wq" in his round
        //else if ( currentCard.card.col == 'w' && currentCard.card.col == 'q' )
        //    progressSave(player);

        // Pass the turn to next player
        if ( reverse == true  )
            counter--;
        else
            counter++;
    }

    // Determine and display who win
    int winPlayerIndex = whoWin(player);
    display_result(winPlayerIndex, round);

    return 0;
}