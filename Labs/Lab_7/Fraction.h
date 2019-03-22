#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;


class Fraction
{
    private:
    //numerator of fraction
        int numerator;
        //denominator of fraction
        int denominator; 
    
    public: 
        //Default constructor
        Fraction();

        //Constructor; User inputs the numerator and denominator
        //@param = top is numerator
        //@param = bottom is denominator
        Fraction(int top, int bottom);

        //Overloads the '+' operator; adds implicit fraction to explicit fraction
        //@return = the final fraction after operation
        Fraction operator+(Fraction Frac);

        //Overloads the '-' operator; subtracts explicit fraction from implicit fraction
         //@return = the final fraction after operation
        Fraction operator-(Fraction Frac);

        //Overloads the '*' operator; multiplies explicit fraction with implicit fraction
         //@return = the final fraction after operation
        Fraction operator*(Fraction Frac);

        //Overloads the '/' operator; flips the explicit fraction and then multiplies it with implicit fraction
         //@return = the final fraction after operation
        Fraction operator/(Fraction Frac);

        //Overloads the input operator; user is asked to enter numerator and denominator
        //@return = fraction input by user 
        friend istream &operator >> (istream &in, Fraction &Frac);

        //Overloads teh output operator; displays it in the format of "(numerator/denominator)"
        //@return = stream in the form of "(numerator/denominator)"
        friend ostream &operator << (ostream &out, Fraction Frac);

        //input validation; only accepts integers
        //@return = integer input by user
        int getInt();
};

#endif