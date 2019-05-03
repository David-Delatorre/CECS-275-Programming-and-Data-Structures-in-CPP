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
    // Point  default constructor
	Point() 
    {
        //initializes both to 0;
        x = 0;
        y = 0;
    } 
	
    // @param takes in a parameter of int data type
    // @param takes in a parameter of int data type
	
	Point(int r, int c) 
	{
        //assign x to row
		x = r; 
        //assign y to col
		y = c; 
	}

	
	//@returns an interger for Point x
	
	int getX() 
	{
		return x;
	}

	
	//@returns an integer for Point y
	
	int getY()
	{
		return y;
	}
};