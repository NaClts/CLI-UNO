# //////////////////////////////////////////////
# /////////// Welcome to HKUNO ///////////
# //////////////////////////////////////////////
ENGG1340 / COMP 2113 Group Project 2023/2024 - Group #21
## Team members(name (UID)in alphabetical order)
- Baek Seunghyeon (3035821659)
- Fan Zihan (3035948471)
- Please add your info here

## Description
UNO is a classic card game that is played with a specially printed deck. The objective of the game is to be the first player to get rid of all your cards. Players take turns matching a card in their hand with the current card shown on top of the deck either by color or number. The game also includes special action cards that can change the course of the game. With this idea, we designed text-based UNO game called HKUNO based on C++. This UNO game supports saving and loading options for players for convenience.  

This UNO game implementation provides a command-line interface to play the game against computer opponents.

## Features
- Play against computer opponents.
- Interactive command-line interface. //change if this is not true
- Special action cards: Draw 2, Reverse, Skip, and Wild cards(Wild and Wild Draw 4).
- The first card is randomly gernerated for the equality.
- Array data structure is used for storing game status ///////////////////////////////fixed more specifically
- Dynamic memory allocation is used for storing player's cards
- File I/O mechanism for storing or loading game status

## Installation
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

## Controls (How to play)
The game is entirely controlled via the command line interface. When it's your turn, you'll be presented with the cards in your hand. Each card will be associated with a number. To play a card, simply type the number associated with that card and press enter.

Special cards like 'skip', 'Draw 2', 'wild', and 'wild draw 4' will be automatically played by the game when drawn.

Please note that the game assumes valid inputs from the user for the seamless gaming experience.

## License


## Credits
- UNO game rules and concept by
- "Contribution" by "Your name"
