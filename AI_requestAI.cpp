#include <iostream>
#include "selfDefStruct.h"


playedUNO easyAI(ListOfCards &player[], int AIIndex, playedUNO &currentCard){ // AI mode is defined based on how the AI search for what card to put
	// easyAI search the array of card and find the first occurrence of appropriate card
	int pos = 0;
	bool found = false;
	if(currentCard.card.col != 'n'){ // check the card and when it is not 'n'
		for (int i = 0; i < 100 ; i++){
			if (player[AIIndex].card[i].col == currentCard.card.col){ // when the card.col is same as currentCard  
				currentCard = player[AIIndex].card[i]; // change the current card
				pos = i;
				found = true;
				break;
			}
			if(player[AIIndedx].card[i] == 0){ // when there is no card anymore
				break;
			}
		}
		if(!found == true){ // if no match card with same color, check for the same number
			for (int i = 0; i < 100 ; i++){
				if (player[AIIndex].card[i].num == currentCard.card.num){ // when the card.num is same as currentCard  
					currentCard = player[AIIndex].card[i]; // change the current card
					pos = i;
					found = true;
					break;
				}
				if(player[AIIndex].card[i] == 0){ // when there is no more card
					break;
				}
			}
		}
		if(found == true){
			for (int j = pos; j < handsize ; j++){ // only for when the player put the card
				player[AIIndex].card[j] = player[AIIndex].card[j + 1]; // remove the card and move the cards to the front
			}
		}
	else{ // decision making after the wild card, we have to check colorTochange not the card color
		for (int i = 0; i < 100 ; i++){
			if (player[AIIndex].card[i].col == currentCard.colorToChange){ // when the card.col is same as colorTochange 
				currentCard = player[AIIndex].card[i]; // change the current card
				pos = i;
				found = true;
				break;
			}
			if(player[AIIndedx].card[i] == 0){ // when there is no card anymore
				break;
			}
		} // in this case we dont need to check the num of card. cuz we have to put the correspond color card.
	}
	return currentCard;
}
	
	
//number of players = numOfPlayer = array size of player[]

playedUNO AI_requestAI(ListOfCards player[AIIndex], int handsize, playedUNO &currentCard){ //player[AIIndex] size is required
	char check_col = currentCard.card.col;
	switch(check_col){
		case 'b':
			currentCard = easyAI(player[], AIIndex, currentCard);
			break;
		case 'r':
			currentCard = easyAI(player[], AIIndex, currentCard);
			break;
		case 'g':
			currentCard = easyAI(player[], AIIndex, currentCard);
			break;
		case 'y':
			currentCard = easyAI(player[], AIIndex, currentCard);
			break;
		case 'n':
			currentCard = easyAI(player[], AIIndex, currentCard);
	}
	return currentCard;
}


