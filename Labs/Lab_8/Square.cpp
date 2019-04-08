#include "Square.h"

//Default constructor; Initializes x, y, and length to 0
Square::Square()
{
    x = 0;
    y = 0;
    length = 0;
}

//Constructor; allows user to input their own values for x, y, and length
Square::Square(int a, int b, int l)
{
    x = a;
    y = b;
    length = l;
}

//Default destructor
Square::~Square(){}

//Overloads the '==' operator to return true if each data value is the same
//@param = a square is passed into the function
//@return = returns true if each of the data members are the same
bool Square::operator==(Square sq)
{
   return ((this -> x == sq.x) && (this -> y == sq.y) && (this -> length == sq.length)); 
}

//Outputs in the form of "Loc = (x, y) Len = length"
ostream &operator<< (ostream &out, Square sq)
{
    out << "Loc = (" << sq.x << ", " << sq.y << ") Len = " << sq.length << endl;
    return out;
}