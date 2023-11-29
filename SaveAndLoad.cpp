#include "SaveAndLoad.h"

void saveGameProgress(std::ofstream& saveFile, ListOfCards player[], int numOfPlayers, playedUNO currentCard, int counter, int round) {
    saveFile.open("savegame.txt", std::ios::out);

    // Save game state to the file
    saveFile << numOfPlayers << " " << counter << " " << round << "\n";
    for (int i = 0; i < numOfPlayers; i++) {
        for (int j = 0; j < initialNumOfCards; j++) {
            saveFile << player[i].card[j].value << " " << player[i].card[j].color << "\n";
        }
    }

    saveFile << currentCard.card.value << " " << currentCard.card.color << " " << currentCard.colourToChange << "\n";

    saveFile.close();
}

void loadGameProgress(std::ifstream& loadFile, ListOfCards player[], int& numOfPlayers, playedUNO& currentCard, int& counter, int& round) {
    loadFile.open("savegame.txt", std::ios::in);

    // Load game state from the file
    loadFile >> numOfPlayers >> counter >> round;
    for (int i = 0; i < numOfPlayers; i++) {
        for (int j = 0; j < initialNumOfCards; j++) {
            loadFile >> player[i].card[j].value >> player[i].card[j].color;
        }
    }

    loadFile >> currentCard.card.value >> currentCard.card.color >> currentCard.colourToChange;

    loadFile.close();
}
