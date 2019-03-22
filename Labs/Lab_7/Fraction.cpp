#include "Fraction.h"

//default constructor - creates fractions
Fraction::Fraction()
{
    numerator = 1;
    denominator = 1;
}

//constructor - creates fractions
//@param top = lets user input a numerator
//@param bottom = lets user input a denominator
Fraction::Fraction(int top, int bottom)
{
    numerator = top;
    denominator = bottom;
}

//Changes '+' operator and overloads it to perform this method
//@param = explicit fraction from constructor
//returns new fraction (after adding both fractions)
Fraction Fraction::operator+(Fraction Frac)
{
    //Checks if denominator is the same
    //if it is the same then add both numerators and keep denominator
    if (this -> denominator == Frac.denominator)
    {
        Fraction frac1(this -> numerator + Frac.numerator, Frac.denominator);
        return frac1;
    }
    //if they denominators aren't the same, multiply the first fraction (num and den) with the second fraction's denominator
    //and multiply the second fraction (num and den) with the first fraction's denominator to get equal denominators, making it
    //legal to add the two numerators. 
    //Final denominator will be denominator1 * denominator2
    else 
    {
        Fraction frac1((this -> numerator * Frac.denominator) + (Frac.numerator * this -> denominator), (Frac.denominator * this -> denominator));
        return frac1;
    }
}

//Overloads the '-' operator and performs this method 
//@param = explicit fraction from constructor
//@return = new fraction after subtracting both fractions
Fraction Fraction::operator-(Fraction Frac)
{
    //the same logic as the '+' operator but subtracting instead of adding
    if (this -> denominator == Frac.denominator)
    {
        Fraction frac1(this -> numerator - Frac.numerator, Frac.denominator);
        return frac1;
    }
    else
    {
        Fraction frac1((this -> numerator * Frac.denominator) - (Frac.numerator * this -> denominator), (Frac.denominator * this -> denominator));
        return frac1;
    }
    
}

//overloads the '*' operator and performs this method
//@param = explicit fraction from constructor
//@return = new fraction after multiplying both fractions
Fraction Fraction::operator*(Fraction Frac)
{
    //multiplies numerator1 to numerator2 to get new numerator and 
    //multiples denominator1 to denominator 2 to get new denominator
    Fraction frac1(this -> numerator * Frac.numerator, this -> denominator * Frac.denominator);
    return frac1;
}

//overloads the '/' operator and performs this method
//@param = explicit fraction from constructor
//@return = new fraction after dividing both fractions
Fraction Fraction::operator/(Fraction Frac)
{
    //flips numerator and denominator of 2nd fraction and multiplies numerator1 and denominator2 for new numerator
    //and multiplies denominator1 and numerator2 for new denominator 
    Fraction frac1 (this -> numerator * Frac.denominator, this -> denominator * Frac.numerator);
    return frac1;
}

//Lets user input a new fraction using the constructor
istream &operator >> (istream &in, Fraction &Frac)
{
    cout << "Enter Numerator: " << endl;
    Frac.numerator = Frac.getInt();
    // in >> Frac.numerator;
    cout << "Enter Denominator: " << endl;
    Frac.denominator = Frac.getInt();
    // in >> Frac.denominator;
    return in;
}

//outputs the fraction in the form of "(numerator/denominator)"
ostream &operator<< (ostream &out, Fraction Frac)
{
    out << '(' << Frac.numerator << '/' << Frac.denominator << ") ";
    return out;
}

//input validation to make sure only integers are input by the user
//@return = valid integer input by user
int Fraction::getInt( ) 
{
	int input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			valid = true;
		} else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout<< "Invalid Input" << endl;
		}
	}
	return input;
}