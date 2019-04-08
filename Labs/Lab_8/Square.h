#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
using namespace std;

class Square
{
    private:
        //Width of square
        int x;
        
        //Height of square
        int y;
        
        //Length of square
        int length;

    public: 
        
        //Default constructor
        Square();
        
        //Constructor = lets user input their own data values
        Square(int a, int b, int l);
        
        //Default destructor
        ~Square();
        
        //Overloads the '==' operator to return true if each of the data members are the same
        bool operator==(Square sq);
        
        //Outputs in the form of "Loc = (x, y) Len = length"
        friend ostream &operator<< (ostream &out, Square sq);
};








#endif