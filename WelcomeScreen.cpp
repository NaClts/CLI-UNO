//WelcomeScreen.cpp

#include <iostream>
#include "WelcomeScreen.h"

using namespace std;

int display_welcomeScreen() {
    int numOfPlayers;

    cout << "Welcome to UNO!\n";
    cout << "Enter the number of players (1-" << 10 << "): ";
    cin >> numOfPlayers;

    // Validate the input
    while (numOfPlayers < 1 || numOfPlayers > 10) {
        cout << "Invalid number of players. Please enter a number between 1 and " << 10 << ": ";
        cin >> numOfPlayers;
    }

    return numOfPlayers;
}
