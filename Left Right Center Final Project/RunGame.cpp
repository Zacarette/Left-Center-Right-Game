#include "GameClass.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(0))); //helps generate a random number for dice rolls

    gameInfo game; //create an instance of the gameInfo class
    game.gameStartUp(); //start the game start up
    game.gameLoop(); //checks game loop

    return 0; //exits program
}