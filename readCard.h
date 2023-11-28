#ifndef READCARD_H
#define READCARD_H

#include <iostream>
#include "selfDefStruct.h"
#include "card_effect.h"

void readCard(ListOfCards& player[AIIndex], playedUNO currentCard, int handsize, int& counter, bool reverse);

#endif // READCARD_H