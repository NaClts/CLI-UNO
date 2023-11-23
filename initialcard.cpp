// initialcard.cpp

#include <iostream>
#include "initialcard.h"

using namespace std;

int display_initialNumOfCards() {
    int initialNumOfCards;

    cout << "Enter the initial number of cards for each player: ";
    cin >> initialNumOfCards;

    // Validate the input
    while (initialNumOfCards <= 0) {
        cout << "Invalid initial number of cards. Please enter a positive number: ";
        cin >> initialNumOfCards;
    }

    return initialNumOfCards;
}
