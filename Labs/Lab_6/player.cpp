#include "player.h"

Player::Player()
{
    dice[3];
    points = 0;
    size = 3;
}

int Player::getPoints()
{
    return points;
}

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
		temp = dice[min];
        dice[min] = dice[i];
        dice[i] = temp;
	}
}

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

bool Player::winCond1()//series +2 points
{
    int d1 = dice[0], d2 = dice[1], d3 = dice[2];
    if (d3 == d2 + 1 && d2 == d1 + 1)   return true;
    return false;
}

bool Player::winCond2()//pair +1 point
{
    int d1 = dice[0], d2 = dice[1], d3 = dice[2];
    if (d1 == d2 || d2 == d3 || d1 == d3)   return true;
    return false;
}

bool Player::winCond3()//three of a kind +3 points
{
    int d1 = dice[0], d2 = dice[1], d3 = dice[2];
    if (d1 == d2 && d2 == d3)   return true;
    return false;
}

bool Player::takeTurn()
{
    Die die;
    for (int i = 0; i < size; i++)
    {
        dice[i] = die.roll();
    }

    displayVal();
    //Checks which win condition is met
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
    else cout << "Aww. Too bad!" << endl;

    points = getPoints();
    cout << "Score = " << points << endl;
    cout << "Play again? (Y/N): ";
    return getYesNo();
}

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