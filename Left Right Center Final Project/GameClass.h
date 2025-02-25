#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PlayerClass.h"

using namespace std;

class gameInfo
{
    private:
    vector<PlayerInfo> players; //vector to hold player info

    public:
    void gameRules() //displays game rules to players
    {
        ifstream rulesFile("LRCrules.txt"); //opens file LRCrules.txt

        //if the file is open then read each line and output its info
        if (rulesFile.is_open())
        {
            string fileTxt;
            while (getline(rulesFile, fileTxt))
            {
                cout << fileTxt << endl;
            }

            rulesFile.close(); //close the file
        }

        //else output message saying unable to open file
        else
        {
            cout << "Unable to open LRCRules.txt" << endl;
        }
    }

    void addPlayers() //adds players to game and stores their name in a dynamic vector
    {
        int playerNum; //variable for user input later

        //prompt user for how many people will be playing and store input
        cout << "\nHow many people will be playing?: ";
        cin >> playerNum;

        //if there is less than 3 players output a message saying you need 3 or more players to play and exit the program
        if (playerNum < 3)
        {
            cout << "You need at least 3 players to play. Please try again when you have 3 or more players, and only enter numeric values.";
            exit(1);
        }

        players.resize(playerNum); //resize the vector to be the size of people playing entered by the user

        //collect player names
        for (int i = 0; i < playerNum; i++)
        {
            string playerName;
            cout << "Enter the name for Player " << (i + 1) << ": ";
            cin >> playerName;

            //create a PlayerInfo object and add it to the vector
            players[i] = PlayerInfo(playerName);
        }
    }

    void gameStartUp() //calls other start up methods to run together
    {
        gameRules();
        addPlayers();

        cout << "\nThe game will now begin!" << endl; //message to let players know the game is starting
    }

    void playerTurn(int currentPlayer) //rolls dice and moves chips
    {
        string playerName = players[currentPlayer].getPlayerName(); //gets current players name and assigns it to variable
        int chips = players[currentPlayer].getPlayerChips(); //gets current players chips and assigns it to variable

        cout << "\nIt is " << playerName << "'s turn." << endl;
        cout << playerName << " has " << chips << " chip(s)." << endl;

        if (chips > 0) //if there are more than 0 chips
        {
            int rolls = (chips > 3) ? 3 : chips; //allows player to roll up to 3 dice or roll the dice the same amount of times as the chips the player has
            
            for (int i = 0; i < rolls; i++) //checks how many times the die should be rolled
            {
                int die = (rand() % 6) + 1; //roll a die
                switch (die)
                {
                    //if roll is 1 = L
                    case 1:
                        cout << playerName << " rolled: L" << endl;
                        chips--; //subtract 1 chip
                        players[(currentPlayer - 1) % players.size()].receiveChips(1); //add 1 chip to the player indexed to the left
                        cout << playerName << " passes a chip to " << players[(currentPlayer - 1 + players.size()) % players.size()].getPlayerName() << "." << endl; //message to show where chip got passed
                        players[currentPlayer].setPlayerChips(chips); //recounts the player's chips
                        break;

                    //if roll is 2 = R
                    case 2:
                        cout << playerName << " rolled: R" << endl;
                        chips--; //subtract 1 chip
                        players[(currentPlayer + 1) % players.size()].receiveChips(1); //add 1 chip to the player indexed to the right
                        cout << playerName << " passes a chip to " << players[(currentPlayer + 1 + players.size()) % players.size()].getPlayerName() << "." << endl; //message to show where chip got passed
                        players[currentPlayer].setPlayerChips(chips); //recounts the player's chips
                        break;

                    //if roll is 3 = C
                    case 3:
                        cout << playerName << " rolled: C" << endl;
                        chips--; //subtract 1 chip for it going to the center
                        cout << playerName << " passes a chip to the center." << endl;
                        players[currentPlayer].setPlayerChips(chips); //recounts the player's chips
                        break;

                    //if roll is 4, 5, or 6 = *
                    case 4:
                    case 5:
                    case 6:
                        cout << playerName << " rolled: *" << endl;
                        break;

                    //should never reach but just incase it does error message and close program with error
                    default:
                        cout << "Error: Unexpected die value " << die << endl;
                        exit(1);
                        break;

                }
            }
        }

        else //player has 0 chips
        {
            cout << playerName << " does not have any chips so they cannot roll the dice." << endl;
        }
    }

    bool checkWinCon() //checks to see if only one players has chips remaining
    {
        int playersWithChips = 0; //counts how many players have chips
        int winnerIndex = -1; //variable to store the index of the winner

        for (int i = 0; i < players.size(); i++)
        {
            if (players[i].getPlayerChips() > 0)
            {
                playersWithChips++; //increase the counter of players of with chips
                winnerIndex = i; //update the winner index
            }
        }

        if (playersWithChips == 1)
        {
            cout << "\n" << players[winnerIndex].getPlayerName() << " has won!" << endl;
            return true; //end game
        }

        return false; //continue game
    }

    void gameLoop() //goes through turns and breaks or continues game loop based on if there is a winner
    {
        bool gameWon = false; //flag to track if the game has been won

        while (!gameWon) //continue game while no winner
        {
            //loop through each player
            for (int currentPlayer = 0; currentPlayer < players.size(); currentPlayer++)
            {
                playerTurn(currentPlayer); //each player takes their turn
            }

            gameWon = checkWinCon(); //after each round check if there is a winner
        }

        cout << "Game over! Thanks for playing."; //game over messsage
    }
};