// onehavenocards.h

#ifndef ONE_HAVE_NO_CARDS_H
#define ONE_HAVE_NO_CARDS_H

// Defining new type of variable "UNO"
// For example,
// ( UNO.col == 'n' && UNO.num == 'D' ) is Draw 4
// ( UNO.col == 'b' && UNO.num == '7' ) is Blue 7
struct UNO {
    char col;   // Colour of UNO card ( 'b' , 'g' , 'r' , 'y' , 'n' )
    char num;   // Number of UNO card ( '0'-'9', 'D'(Draw), 'R'(Reverse), 'S'(Skip) )
};

// Define a structure to store all the cards of a player
struct ListOfCards {
    UNO card[100];      // Maximum number of cards can be owned by a player is 100
};

bool onePlayerNoCards(ListOfCards player[], int numOfPlayer);
int getNumOfCards(ListOfCards player);

#endif // ONE_HAVE_NO_CARDS_H
