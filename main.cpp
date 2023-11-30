// main.cpp

#include <iostream>
#include <fstream>  // for filr input/output
#include <cstdlib>  // For calling srand(), rand()
#include <ctime>    // For calling time()
#include "onehavenocards.h"
#include "selfDefStruct.h"    // For calling struct UNO & ListOfCards
#include "random.h" // For calling randomSingleUNO()
#include "AI_requestAI.h" // For calling AI_requestAI()
#include "card_effect.h" // For calling card_effect functions
#include "display_requestUser.h" // For calling display_requestUser()
#include "display_waitingForAI.h"   // For calling display_waitingForAI.h()

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

void getValidNumPlayers(int*& numPlayers) {
    numPlayers = new int;

    do {
        cout << "Enter the number of players (2-10): ";
        cin >> *numPlayers;

        if (*numPlayers >= 2 && *numPlayers <= 10) {
            break;  // Valid input, exit the loop
        }
        else {
            cout << "Invalid input. Please enter a number between 2 and 10." << endl;
        }
    } while (true);

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
    int* numOfPlayers
    getValidNumPlayers(numOfPlayers);
    int initialNumOfCards = getValidInitialNumOfCards();

    cout << "\nNew game started with " << *numOfPlayers << " players and initial hand size of " << initialNumOfCards << "." << endl;

    // Maximum number of players is 10
    ListOfCards player[10];

    // Randomly assign initial UNO cards to all players
    for (int i = 0; i < *numOfPlayers; i++) {
        for (int j = 0; j < initialNumOfCards; j++)
            player[i].card[j] = randomSingleUNO(time(NULL) + i + j);
    }

    bool reverse = false;   // For reverse card - true if reverse card is played
    int counter = 0;        // The remainder of counter / numOfPlayers telling which player is going to play
    int round = 0;          // For the leaderboard

    playedUNO currentCard;

    // Initialize the starting card
    currentCard.card = randomSingleUNO(time(NULL) - 123456);
    currentCard.colourToChange = 'n';
    // Exclude non-coloured card as initial card
    if ( currentCard.card.col == 'n' ) {
        currentCard.card.col = 'b';
        currentCard.card.num = '0';
    }

    // Each loop asks a player (user or AI) to play a suitable card, then determine and execute the action of the played card
    // Exit the loop when one of the player played all of his/her cards
    // If the number of cards holding by a player exceeds 100,
    // => the player can still draw a card,
    // => but a random card will be discarded automatically.
    bool crowned = false;
    while (!onePlayerNoCards(player[], *numOfPlayers)) {
        // Ask for input of playing card from user or AI
        if (counter % *numOfPlayers == 0)    // The turn of user
            currentCard = display_requestUser(player[], currentCard, numOfPlayers);    // The card played by player is stored as "currentCard"
        else {
            int AIIndex = counter % *numOfPlayers;    // The turn of AI
            display_waitingForAI(currentCard, AIIndex, player[0]); // Display which AI is playing and wait for a time delay of 1 second
            currentCard = AI_requestAI(player[], AIIndex ,currentCard); // The card played by AI is stored as "currentCard"

        } 
        ///////////////////////////////////////////
        // (TO BE FILLED) Action after each cards//
        ///////////////////////////////////////////
    char check_col = currentCard.card.col;
    char check_num = currentCard.card.num;
    // check the color whether it is 'n' or not
    if(check_col != 'n'){ //if it is not, card effect only for D, R, S
		switch(check_num){
			case 'D':
				if(reverse == false){ //when it is not reverse, card should be added to next player(counter++)
					Draw2(player[], (counter+1)%*numOfPlayers);
				}
				else{//when it is reverse, card should be added to next player(counter--)
					Draw2(player[], (counter-1)%*numOfPlayers);
				}
				break;
			case 'R':
				reverse = (reverse == false) ? true : false; // when reverse == false, then set true and vice versa
				break;
			case 'S':
				skip(counter, reverse);
				break;
		}
	}
	else{ // if the color is 'n', only 'W', 'D' 
		switch(check_num){
			case 'W':
				Wild(currentCard);
				break;
			case 'D':
				if(reverse == false){//when it is not reverse, card should be added to next player(counter++)
					WildDraw(player[], (counter+1)%*numOfPlayers);
				}
				else{//when it is reverse, card should be added to next player(counter--)
					WildDraw(player[], (counter-1)%*numOfPlayers);
				}
				break;
		}
	}
        // Pass the turn to the next player
        if (reverse == true)
            counter--;
        else
            counter++;
       
        // Determine and display who wins while no one played all the cards
        int winPlayerIndex = whoWin(player[], *numOfPlayers);
        if (winPlayerIndex > -1) {
            display_result(winPlayerIndex, round);
            crowned = true;
            break;
        }
        saveGameProgress(saveFile, player, numOfPlayers, currentCard, counter, round);
    }

    // Determine and display who wins while someone played all the cards
    if (crowned == false){
        winPlayerIndex = whoWin(player[], *numOfPlayers);
        display_result(winPlayerIndex, round);
    }
    delete numOfPlayers; 
}

int main() {
    int choice;

    do {
        displayWelcomeScreen();

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            startNewGame();
            break;
        case 2:
            // Add code for loading game
            cout << "Loading game..." << endl;
            break;
        case 3:
            // Add code for about game
            cout << "UNO Game - About" << endl;
            break;
        case 4:
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

        cout << endl;

    } while (choice != 4);

    return 0;
}

