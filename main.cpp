// main.cpp

#include <iostream>
#include <cstdlib>  // For calling srand(), rand()
#include <ctime>    // For calling time()
#include "onehavenocards.h"
#include "selfDefStruct.h"    // For calling struct UNO & ListOfCards
#include "random.h" // For calling randomSingleUNO()
using namespace std;


// Display the welcome screen and ask user to choose the game mode (i.e. the number of player)
// Return the number of player (MAX: 10)
void displayWelcomeScreen() {
    cout << "==== Welcome to UNO Game ====" << endl;
    cout << "1. Start New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. About Game" << endl;
    cout << "4. Exit" << endl;
}

int getValidNumPlayers() {
    int numPlayers;

    do {
        cout << "Enter the number of players (2-10): ";
        cin >> numPlayers;

        if (numPlayers >= 2 && numPlayers <= 10) {
            break;  // Valid input, exit the loop
        }
        else {
            cout << "Invalid input. Please enter a number between 2 and 10." << endl;
        }
    } while (true);

    return numPlayers;
}

int getValidInitialNumOfCards() {
    int initialNumOfCards;

    do {
        cout << "Enter the initial hand size: ";
        cin >> initialNumOfCards;

        if (initialNumOfCards > 0) {
            break;  // Valid input, exit the loop
        }
        else {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    } while (true);

    return initialNumOfCards;
}

void startNewGame() {
    int numOfPlayers = getValidNumPlayers();
    int initialNumOfCards = getValidInitialNumOfCards();

    cout << "\nNew game started with " << numOfPlayers << " players and initial hand size of " << initialNumOfCards << "." << endl;
}

int main() {
    int numOfPlayer = display_welcomeScreen();
    int initialNumOfCards = display_initialNumOfCards();

    // Maxiumun number of players is 10
    ListOfCards player[10];

    // Randomly assign initial UNO cards to all players
    for (int i=0; i<numOfPlayer; i++) {
        for (int j=0; j<initialNumOfCards; j++)
            player[i].card[j] = randomSingleUNO( time(NULL) + j );
    }

    bool reverse = false;   // For reverse card - true if reverse card is played
    int counter = 0;        // The remainder of counter / numOfPlayer telling which player is going to play
    int round = 0;          // For the leaderboard

    playedUNO currentCard;

    // Initialize the starting card
    currentCard.card = randomSingleUNO( time(NULL) - 123456 );
    currentCard.colourToChange = 'n';

    // Each loop asks a player (user or AI) to play a suitable card, then determine and execute the action of the played card
    // Exit the loop when one of the player played all of his/her cards
    // If the number of cards holding by a player exceeds 100,
    // => the player can still draw a card,
    // => but a random card will be discarded automatically.
    while( !onePlayerNoCards(ListOfCards player[], int numOfPlayer) ) {

        // Ask for input of playing card from user or AI
        if ( counter % numOfPlayer == 0 )    // The turn of user
            currentCard = display_requestUser(player[0], currentCard);    // The card played by player is stored as "currentCard"
        else
            int AIIndex = counter % numOfPlayer;    // The turn of AI
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
