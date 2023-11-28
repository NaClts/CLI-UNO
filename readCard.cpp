//readCard function
#include <iostream>
#include "selfDefStruct.h"
#include "card_effect.h"

void readCard(ListOfCards &player[AIIndex], playedUNO currentCard, int handsize, int &counter, bool reverse){
	//effect only for draw2, reverse, skip
	char check_col = currentCard.card.col;
	char check_num = currentCard.card.num;
	if(check_col != 'n'){
		switch(check_num){
			case 'D':
				Draw2(player[AIIndex], handsize);
				break;
			case 'R':
				reverse = true;
				break;
			case 'S':
				skip(counter, reverse);
				break;
		}
	}
	else{
		switch(check_num){
			case 'W':
				Wild(currentCard);
				break;
			case 'D':
				WildDraw(player[AIIndex], handsize);
				break;
		}
	}
}