//AI_requestAI.h

#ifndef AI_REQUESTAI_H
#define AI_REQUESTAI_H
#include "selfDefStruct.h"

playedUNO easyAI(ListOfCards &player[AIIndex], int handsize, playedUNO &currentCard);
playedUNO AI_requestAI(ListOfCards &player[AIIndex], int handsize, playedUNO &currentCard);

#endif