#include "player.h"



//Input validation; checks whether or not the user inputs a Yes or a No as well as 
//all 5 variations of Yes/No; if the input is invalid, prompts user to try again until success
//@return = returns a true if the user says yes and a false if the user says no
bool getYesNo( ) 
{
	string input;
	bool valid = false;
	while(!valid) {
		cin >> input;
		if(input == "yes" || input == "Yes" || input == "YES" || input == "Y" || input == "y") {
			return true;
		} else if(input == "no" || input == "No" || input == "NO" || input == "N" || input == "n") {
			return false;
		} else {
			cout<< "Invalid Input (Y/N)" << endl;
		}
	}
	return false;
}
//Calls function from player.cpp 
int main()
{
    //play is used to call functions from player.cpp/player.h
    Player play;
    bool keepPlay = true;
    //For the random integer (rolling of the die) 
    srand(time(NULL));
    while (keepPlay) 
    {
        play.takeTurn();
        cout << "Play again? (Y/N): ";
        keepPlay = getYesNo();
        //cout << endl << die.roll() << endl;
    }
    //Displays final score after the user quits
    cout << "Game Over!\nFinal score = " << play.getPoints() << " points.";
    return 0;
}

