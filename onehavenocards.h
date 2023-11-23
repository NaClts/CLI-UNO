// onehavenocards.h

#ifndef ONE_HAVE_NO_CARDS_H
#define ONE_HAVE_NO_CARDS_H

// Defining new type of variable "UNO"
// For example,
// ( UNO.col == 'n' && UNO.num == 'D' ) is Draw 4
// ( UNO.col == 'b' && UNO.num == '7' ) is Blue 7
struct UNO {
    char col;
    char num;
};

struct ListOfCards {
    UNO card[100];
};

bool onePlayerNoCards(ListOfCards player[], int numOfPlayer);
int getNumOfCards(ListOfCards player);

#endif // ONE_HAVE_NO_CARDS_H
