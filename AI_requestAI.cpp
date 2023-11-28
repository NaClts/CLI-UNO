#include <iostream>
#include "selfDefStruct.h"


playedUNO easyAI(ListOfCards &player[AIIndex], int handsize, playedUNO &currentCard){ // AI mode is defined based on how the AI search for what card to put
	// easyAI search the array of card and find the first occurrence of appropriate card
	int pos = 0;
	bool found = false;
	for (int i = 0; i < handsize ; i++){
		if (player[AIIndex].card[i].col == currentCard.card.col){ // when the card.col is same as currentCard  
			currentCard = player[AIIndex].card[i]; // change the current card
			pos = i;
			found = true;
			break;
		}
	}
	if(!found){ // if no match card with same color, check for the same number
		for (int i = 0; i < handsize ; i++){
		if (player[AIIndex].card[i].num == currentCard.card.num){ // when the card.num is same as currentCard  
			currentCard = player[AIIndex].card[i]; // change the current card
			pos = i;
			found = true;
			break;
			}
		}
	}
	for (int j = pos; j < handsize ; j++){
		player[AIIndex].card[j] = player[AIIndex].card[j + 1]; // remove the card and move the cards to the front
	}
	return currentCard;
}
//number of players = numOfPlayer = array size of player[]

playedUNO AI_requestAI(ListOfCards player[AIIndex], int handsize, playedUNO &currentCard){ //player[AIIndex] size is required
	char check_col = currentCard.card.col;
	switch(check_col){
		case 'b':
			currentCard = easyAI(player[AIIndex], handsize, currentCard);
			break;
		case 'r':
			currentCard = easyAI(player[AIIndex], handsize, currentCard);
			break;
		case 'g':
			currentCard = easyAI(player[AIIndex], handsize, currentCard);
			break;
		case 'y':
			currentCard = easyAI(player[AIIndex], handsize, currentCard);
			break;
	}
	return currentCard;
}


