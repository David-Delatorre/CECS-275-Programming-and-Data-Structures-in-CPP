#include "player.h"

//Calls function from player.cpp 
int main()
{
    //play is used to call functions from player.cpp/player.h
    Player play;
    //For the random integer (rolling of the die) 
    srand(time(NULL));
    //Continuously calls takeTurn from player.cpp until a user inputs a No
    while (play.takeTurn()) continue;
    //Displays final score after the user quits
    cout << "Game Over!\nFinal score = " << play.getPoints() << " points.";
    return 0;
}