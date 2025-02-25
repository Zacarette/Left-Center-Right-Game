#include <string>

using namespace std;

class PlayerInfo
{
    private:
    string playerName; //store players name
    int playerChips; //store number of chips player has

    public:
    PlayerInfo() : playerName(""), playerChips(0) {} //default constructor

    PlayerInfo(string name) : playerName(name), playerChips(3) {} //constructor that initializes player name and sets their chips to 3

    //getter for player name
    string getPlayerName() const
    {
        return playerName;
    }

    //setter for player name
    void setPlayerName(const string& name)
    {
        playerName = name;
    }

    //getter for player chips
    int getPlayerChips() const
    {
        return playerChips;
    }

    //setter for player chips
    void setPlayerChips(int chips)
    {
        //makes sure the number of chips does not go below 0
        if (chips >= 0)
        {
            playerChips = chips;
        }
        
    }

    //method to receive chips
    void receiveChips(int amount)
    {
        playerChips += amount;
    }
};