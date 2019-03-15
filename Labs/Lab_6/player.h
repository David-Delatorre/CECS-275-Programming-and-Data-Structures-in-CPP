#ifndef PLAYER_H
#define PLAYER_H

#include "die.h"

//In-depth description of instance variables and methods in player.cpp
class Player
{
    private: 
    //Sets Instance Variables that are used throughout the class
    //dice is a set array of 3 dice
    //points is the amount of points garnered while playing the game
    //size is the amount of dice tossed/size of the array
        Die dice[3];
        int points;
        int size;
    
    public:
    //Methods are predefined here to be used in program file
        Player();//default constructor
        int getPoints();//gets the total points accumulated
        void sortDie();//sorts the dice in ascending order
        void displayVal();//displays the dice rolled
        bool winCond1();//series
        bool winCond2();//pair
        bool winCond3();//three of a kind
        void takeTurn();//calls every other function in this class; practically the main() of this class
};

#endif