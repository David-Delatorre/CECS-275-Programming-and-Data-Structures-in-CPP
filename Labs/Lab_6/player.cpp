#include "player.h"

//Default constructor: Sets default size of dice tossed and the points received.
//Dice[] is an array of 3 dice, each element being a random number determined by the roll function
//Points is an integer of the points accumulated throughout the program
//Size is the size of the array (3) in this case
Player::Player()
{
    dice[3];
    points = 0;
    size = 3;
}

//Gets the amount of points at the time it is called
//@return = returns the amount of points accumulated up to this moment
int Player::getPoints()
{
    return points;
}

//The dice is sorted from least to greatest (ascending order)
void Player::sortDie()
{
    int min;
    int temp;
    for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (dice[j] < dice[min])	min = j;
		}
        //sorts the die using selection sort
		temp = dice[min];
        dice[min] = dice[i];
        dice[i] = temp; 
	}
}

//Displays the value of each dice rolled. Gives us values of 
//dice 1, dice 2, and dice 3; can theoretically go up to as many dice as needed
void Player::displayVal()
{
    sortDie();
    cout << "\nRolling Dice...";
    for (int i = 0; i < size; i++)
    {
        if (size - 1 == i)
        {
            cout << "D" << i+1 << " = " << dice[i] << endl;
        }
        else cout << "D" << i+1 << " = " << dice[i] << ", ";
    }
}

//First win condition: Series of numbers (ie: 1-2-3, 2-1-3, 3-1-2, 4-5-6)
//Uses the dice[] array and checks elements inside; dice are assigned to d1, d2, and d3
//Dice elements are then compared to check if they are in series
//Dice are also already sorted when this function is called
//@return = returns true if the dice are in series and false otherwise
bool Player::winCond1()//series +2 points
{
    int d1 = dice[0], d2 = dice[1], d3 = dice[2];
    if (d3 == d2 + 1 && d2 == d1 + 1)   return true;
    return false;
}

//Second win condition: A pair of two numbers (ie: 1-2-2, 6-6-5, etc.)
//Uses the dice[] array and checks elements inside; dice are assigned to d1, d2, and d3
//Dice elements are then compared to check if the array contains a pair of 2 identical numbers
//Dice are already sorted when this function is called
//@return = returns true if the dice contains a pair and false otherwise
bool Player::winCond2()//pair +1 point
{
    int d1 = dice[0], d2 = dice[1], d3 = dice[2];
    if (d1 == d2 || d2 == d3 || d1 == d3)   return true;
    return false;
}

//Third and final win condition: A three of a kind (ie: 1-1-1, 2-2-2, 5-5-5)
//Uses the dice[] array and checks elements inside; dice are assigned to d1, d2, and d3
//Dice elements are then compared to check if the array contains a three of a kind (3 identical numbers)
//Dice are already sorted when this function is called
//@return = returns true if the dice contains a three of a kind and false otherwise
bool Player::winCond3()//three of a kind +3 points
{
    int d1 = dice[0], d2 = dice[1], d3 = dice[2];
    if (d1 == d2 && d2 == d3)   return true;
    return false;
}

//Creates a Die constructor called die from die.cpp/die.h
//This allows us to use functions regarding rolling the dice and getting values from them 
//These functions are found in die.cpp and die.h
//@return = returns a true if the user decides to play again, otherwise returns false
bool Player::takeTurn()
{
    Die die;
    //Assigns 3 random integers to the array of the 3 dice rolled
    //die calls the roll() function which returns a random integer (1-6)
    for (int i = 0; i < size; i++)
    {
        dice[i] = die.roll();
    }

    //Displays the random dice that have just been rolled
    displayVal();
    //Checks which win condition is met
    //Is in if/else if to make sure only one win condition is met
    //Displays which win condition is met and then increments the points by the amount of points 
    //each win returns. Three of a kind adds 3 points, a pair adds 1 point, and a series adds 2 points
    if (winCond3()) 
    {
        cout << "You got a three of a kind!\n";
        points = points + 3;
    }        
    else if (winCond2())
    {
        cout << "You got a pair!\n";
        points = points + 1;
    }    
    else if (winCond1())    
    {
        cout << "You got a series of 3!\n";
        points = points + 2;
    }
    //If none of the win conditions are met
    else cout << "Aww. Too bad!" << endl;

    //Retrieves the amount of points accumulated at this moment and displays the players' current score
    //Prompts the player to input a yes or no whether or not they want to play again
    points = getPoints();
    cout << "Score = " << points << endl;
    cout << "Play again? (Y/N): ";
    return getYesNo();
}

//Input validation; checks whether or not the user inputs a Yes or a No as well as 
//all 5 variations of Yes/No; if the input is invalid, prompts user to try again until success
//@return = returns a true if the user says yes and a false if the user says no
bool Player::getYesNo( ) 
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