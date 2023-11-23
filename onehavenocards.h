// onehavenocards.h

#ifndef ONE_HAVE_NO_CARDS_H
#define ONE_HAVE_NO_CARDS_H

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
