#include "die.h"

//Default constructor: assigns 6 sides to the die and sets a default value of 1
//Sides = amount of sides the die has (possible values)
//Value = the value that the die lands on
Die::Die()
{
    sides = 6;
    value = 1;
}
//Constructor: Assigns s amount of sides to the die and sets the default value to 1
//Sides = amuount of sides that the die has
//Value = side that the die lands on
//@param = int s is the amount of sides the user wants to put on their die
Die::Die(int s) 
{
    sides = s;
    value = 1;
}

//Rolls the die; gives us a number between 1 and the amount of sides the die has
//@return = returns the value that the die toss lands on
int Die::roll()
{
    value = rand() % sides + 1;
    return value;
}

//Retrieves value of die at this point of time 
//@return = returns the value that the die toss lands on
int Die::getValue()
{
    return value;
}

//Lets the user input a value for the die to land on. This value must be between 1 and the amount of sides (inclusive)
//that the die has. If the user input is valid, then the int val is assigned to value
//@param = User set value to assign to die
//@return = returns true if the value set is valid; returns false if it is invalid
bool Die::setValue (int val)
{
    if (val > 0 && val <= sides)
    {
        value = val;
        return true;
    }
    return false;
}