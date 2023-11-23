// onehavenocards.cpp

#include "onehavenocards.h"

bool onePlayerNoCards(ListOfCards player[], int numOfPlayer) {
    for (int i = 0; i < numOfPlayer; i++) {
        if (getNumOfCards(player[i]) == 0) {
            return true; // At least one player has no cards
        }
    }
    return false; // All players have at least one card
}

int getNumOfCards(ListOfCards player) {
    int count = 0;
    while (player.card[count].col != '\0' && player.card[count].num != '\0') {
        count++;
    }
    return count;
}
