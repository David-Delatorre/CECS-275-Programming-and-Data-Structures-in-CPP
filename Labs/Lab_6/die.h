#ifndef DIE_H
#define DIE_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

//In-depth description of instance variables and methods are in die.cpp
class Die   
{
    
    private:
    //Sets instance variables that are used throughout the class
    //Represents a single die that can be initialized by any number of sides
    //sides is the number of sides on the die
    //value is the side that the die lands on 
        int sides;
        int value;
    
    public:
    //Methods are predefined here to be used in program file
        Die();//default constructor
        Die(int s);//dynamic constructor; user can input amount of sides on the die
        int roll();//"rolls" the die and returns the side it "lands" on
        int getValue();//retrieves the value of the die and returns it
        bool setValue (int val);//user input allows user to force the die to land on val (as long as it's within range)
};

#endif