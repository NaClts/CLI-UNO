#include <iostream>
#include <cstdlib>
#include <ctime>
#include "selfDefStruct.h"
#include "random.h"

void skip(int &counter, bool reverse){ // skip the next player's turn 
	if(reverse){
		count--;
	}
	else{
		count++;
	}
}

void Draw2(ListOfCards &player[AIIndex], int handsize){ // adding 2 cards to the player
	UNO add_card1, add_card2;
	add_card1 = randomSingleUNO(time(NULL)); // random 2 cards from the deck
	add_card2 = randomSingleUNO(time(NULL));
	for(int i = 0; i < handsize ; i++){ // add the random card at the back of the array
		if(player[AIIndex].card[i] == 0){
			player[AIIndex].card[i] = add_card1;
			player[AIIndex].card[i+1] = add_card2;
			break;
		}
	}
}

void Wild( playedUNO &currentCard, int size){ //change the color 
	char changeToColor;
	cin >> changeToColor;
	switch(changeToColor){
		case 'b':
			currentCard.card.col = 'b';
			currentCard.car.num = '0'; //set the card num = 0
			break;
		case 'r':
			currentCard.card.col = 'r';
			currentCard.car.num = '0'; //set the card num = 0
			break;
		case 'g':
			currentCard.card.col = 'g';
			currentCard.car.num = '0'; //set the card num = 0
			break;
		case 'y':
			currentCard.card.col = 'y';
			currentCard.car.num = '0'; //set the card num = 0
			break;
	}
}

void WildDraw(ListOfCards &player[AIIndex], int handsize){// adding 4 cards to the player 
	UNO add_card1, add_card2, add_card3, add_card4;
	add_card1 = randomSingleUNO(time(NULL)); // generate 4 random cards
	add_card2 = randomSingleUNO(time(NULL));
	add_card3 = randomSingleUNO(time(NULL));
	add_card4 = randomSingleUNO(time(NULL));
	for(int i = 0; i < handsize ; i++){ // add the random card at the back of the array
		if(player[AIIndex].card[i] == 0){
			player[AIIndex].card[i] = add_card1;
			player[AIIndex].card[i+1] = add_card2;
			player[AIIndex].card[i+2] = add_card3;
			player[AIIndex].card[i+3] = add_card4;
			break;
		}
	}
	
}
