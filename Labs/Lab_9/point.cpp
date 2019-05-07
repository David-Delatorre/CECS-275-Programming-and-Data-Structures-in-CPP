#include <iostream>
using namespace std;

class Point 
{
private:
	int x;//point x
	int y;//point y
    
public:
	Point() //default constructor that sets x and y to 0
	{
		x = 0;
		y = 0;
	};

    //Overloaded constructor
    //@param xVal = x value to be passed into x
    //@param yVal = y value to be passed into y
	Point( int xVal, int yVal)
	{
		x = xVal;
		y = yVal;
	};

    //Retrieves the x value
    //@return x
	int getX()
	{
		return x;
	}

    //Retrieves the y value
    //@return y
	int getY()
	{
		return y;
	}
};