#ifndef SAVE_AND_LOAD_H
#define SAVE_AND_LOAD_H

#include <fstream>
#include "selfDefStruct.h"
using namespace std;

void saveGameProgress(ofstream& saveFile, ListOfCards player[], int numOfPlayers, playedUNO currentCard, int counter, int round);
void loadGameProgress(ifstream& loadFile, ListOfCards player[], int& numOfPlayers, playedUNO& currentCard, int& counter, int& round);

#endif 
