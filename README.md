# Left Center Right (LCR) Game
## About the Game
Left Center Right (LCR) is a multiplayer dice game where players roll dice and pass chips according to specific rules. The goal is to win all of the chips, and the game continues until only one player remains with chips. This project simulates the LCR game using C++.
## Files
### GameClass.h
Contains the `gameInfo` class that manages the game's logic. It handles:  
- Displaying the game rules.  
- Adding players to the game.  
- Managing each player's turn, including rolling dice and passing chips.  
- Checking for a winner.  
- Running the game loop.
### LRCrules.txt
This text file contains the official rules for playing Left Center Right (LCR):  
- **Dice:** Each die has the letters L, R, and C, which direct where the player’s chips are passed. Dots on the die do nothing.  
- **Chips:** Players start with three chips, and the number of dice they roll depends on the number of chips they have.  
- **Winning the Game:** The game ends when one player has all the chips.
### PlayerClass.h
Defines the `PlayerInfo` class, which stores information about each player, including their name and the number of chips they have. It also includes methods to:  
- Get and set the player’s name and chip count.  
- Receive chips from other players.
### RunGame.cpp
Contains the main() function, which starts the game. It initializes the gameInfo object, runs the game setup and loop, and exits when the game is over.
## Installation
1. **Clone the repositry in Git Bash:**
   `git clone https://github.com/Zacarette/SNHU-IT-312.git`
2. Ensure that the C++ compiler (e.g., g++ or Visual Studio) is installed.
3. Compile and run the program.
## Usage
1. When the game starts, the rules of the game will be displayed.
2. You will be asked to enter the number of players (minimum 3 players).
3. Enter the names of each player.
4. The game will begin, and each player will take turns rolling dice and passing chips as described in the rules.
5. The game will continue until one player has all the chips and is declared the winner.
## How to Play
1. **The Dice:**
   - L (Left): Pass one chip to the player on your left.
   - R (Right): Pass one chip to the player on your right.
   - C (Center): Place one chip in the center pot (out of play).
   - Dot: No action is required.
2. **The Chips:**
   - Players start with three chips.
   - Players roll a number of dice equal to the number of chips they have (max 3 dice).
   - If a player has no chips left, they cannot roll and must wait for other players to pass chips to them.
3. **Winning:** The winner is the last player with chips remaining.
## Author
Michael Zaccaria
