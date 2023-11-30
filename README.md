# //////////////////////////////////////////////
# /////////// Welcome to HKUNO ///////////
# //////////////////////////////////////////////
ENGG1340 / COMP 2113 Group Project 2023/2024 - Group #21
## Team members(name (UID)in alphabetical order)
- Baek Seunghyeon (3035821659)
- Fan Zihan (3035948471)
- Fu Wenqi (3036098053)
- Wei Jianfeng (3036094899)
- Tong Cheuk Yin (3036068503)

## Description
UNO is a classic card game that is played with a specially printed deck. The objective of the game is to be the first player to get rid of all your cards. Players take turns matching a card in their hand with the current card shown on top of the deck either by color or number. The game also includes special action cards that can change the course of the game. With this idea, we designed text-based UNO game called HKUNO based on C++. This UNO game supports saving and loading options for players for convenience.  

This UNO game implementation provides a command-line interface to play the game against computer opponents.

## Features
- Play against computer opponents.
- Interactive command-line interface. //change if this is not true
- Special action cards: Draw 2, Reverse, Skip, and Wild cards(Wild and Wild Draw 4).
- The first card is randomly gernerated for the equality.(Generation of random game sets or events)
- Array data structure is used for storing game status. ///////////////////////////////fixed more specifically
- Dynamic memory allocation is used for storing player's cards (Dynamic Memory Management)
- File I/O mechanism for storing or loading game status.(File Input/Output)
- Each critical function (e.g. AI behavior, card effect, etc) is stored in different files rather than main program (Program codes in multiple files)
- Each functions and variable used are in proper name style with correct indentation (Proper indentation and naming style)
- Each blocks or lines of code includes explanation for its role (In-code documentation)

## Compliation & Installation
1. Clone the repository: 'add github link here'
2. Navigate to the project directory: `cd uno-game`
3. Compile the source code: `gcc uno.c -o uno`
4. Run the game: `./uno`

## Usage
- Upon starting the game, you will be prompted to enter the number of computer opponents and the number of cards for each player starts with.
- The game will display the current card on top of the deck and your hand.
- Follow the instructions to play your turn, either by selecting a card to play or drawing a card.
- The game will automatically simulate the turns of computer opponents.
- Continue playing until a player wins by getting rid of all their cards.

## Controls & Instructions (How to play)
Starting the Game: 
The game starts by dealing a certain number of cards to each player. The remaining deck is placed in the center and the top card is revealed to start the discard pile.

During Your Turn: 
During your turn, you must match a card from your hand to the card on the top of the discard pile. The match can be based on number, color, or symbol.

Special Cards: 
There are special cards in the game like 'Skip', 'Reverse', 'Draw Two', 'Wild', and 'Wild Draw Four' which have unique effects on the gameplay.

AI Players: 
The game features AI players. Their behavior is defined in the AI_requestAI.cpp file.

Saving and Loading Game Progress: 
You can save and load game progress. The functionality for this is defined in SaveAndLoad.cpp.

Ending Your Turn: 
If you cannot play a card from your hand, you have to draw a card from the deck.

Winning the Game: 
The first player to get rid of all their cards in hand is the winner.

Please note that the game assumes valid inputs from the user for the seamless gaming experience.

## Non-standard C/C++ libraries


## Credits
- UNO game rules and concept by
- "Contribution" by "Your name"
