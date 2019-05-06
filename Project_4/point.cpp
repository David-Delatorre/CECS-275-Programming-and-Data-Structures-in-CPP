#include <iostream>
using namespace std;

class Point
{
private:
	//row coord
	int x;
    //col coord
	int y;

public:
    //Default constructor
	Point() 
    {
        //initializes both to 0;
        x = 0;
        y = 0;
    } 
	
	//Overloaded constructor
    // @param takes in a parameter of int data type
    // @param takes in a parameter of int data type
	Point(int r, int c) 
	{
        //assign x to row
		x = r; 
        //assign y to col
		y = c; 
	}

	//Gets the X coordinate point
	//@returns coordinate point x
	
	int getX() 
	{
		return x;
	}

	
	//Gets the Y coordinate point
	//@returns coordinate point y
	int getY()
	{
		return y;
	}
};