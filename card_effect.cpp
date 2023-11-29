#include <iostream>
#include <cstdlib>
#include <ctime>
#include "selfDefStruct.h"
#include "random.h"
using namespace std;

void skip(int &counter, bool reverse){ // skip the next player's turn 
	if(reverse){
		count--;
	}
	else{
		count++;
	}
}

void Draw2(ListOfCards &player[], int AIIndex){ // adding 2 cards to the player
	UNO add_card1, add_card2;
	add_card1 = randomSingleUNO(time(NULL)); // random 2 cards from the deck
	add_card2 = randomSingleUNO(time(NULL));
	for(int i = 0; i < 100 ; i++){ // add the random card at the back of the array
		if(player[AIIndex].card[i] == 0){
			player[AIIndex].card[i] = add_card1;
			player[AIIndex].card[i+1] = add_card2;
			break;
		}
	}
}

void Wild( playedUNO &currentCard){ //change the color 
	char changeToColor; // getting input from the user
	cin >> changeToColor; //here only valid inputs are 'b', 'r', 'g', 'y' 
	switch(changeToColor){
		case 'b':
			currentCard.colorTochange = 'b';
			break;
		case 'r':
			currentCard.colorTochange = 'r';
			break;
		case 'g':
			currentCard.colorTochange = 'g';
			break;
		case 'y':
			currentCard.colorTochange = 'y';
			break;
		//default: when need to add the default for invalid inputs
			
	}
}

void WildDraw(ListOfCards &player[], int AIIndex){// adding 4 cards to the player 
	UNO add_card1, add_card2, add_card3, add_card4;
	add_card1 = randomSingleUNO(time(NULL)); // generate 4 random cards
	add_card2 = randomSingleUNO(time(NULL));
	add_card3 = randomSingleUNO(time(NULL));
	add_card4 = randomSingleUNO(time(NULL));
	for(int i = 0; i < 100 ; i++){ // add the random card at the back of the array
		if(player[AIIndex].card[i] == 0){
			player[AIIndex].card[i] = add_card1;
			player[AIIndex].card[i+1] = add_card2;
			player[AIIndex].card[i+2] = add_card3;
			player[AIIndex].card[i+3] = add_card4;
			break;
		}
	}
	
}
