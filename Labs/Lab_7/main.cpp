#include "Fraction.h"

#include <iostream>

//Prints out the menu
void menu()
{
    cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Division\n5. Enter Two New Fractions\n6. Quit\n";
}

//User input is limited to a range of numbers from low to high
//@param low = floor of range
//@param high = ceiling of range
//@return = returns number the user input, if valid
int getIntRange(int low, int high) 
{
	int input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			if(input >= low && input <= high) {
				valid = true;
			} else {
				cout<< "Invalid Input" << endl;
			}
		} else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout<< "Invalid Input" << endl;
		}
	}
	return input;
}

int main()
{
    Fraction frac1;
    Fraction frac2;
    bool keepGoing = true;
    cout << "Enter Fraction 1: \n";
    cin >> frac1;
    cout << "Enter Fraction 2: \n";
    cin >> frac2;
    while (keepGoing)
    {
        menu();
        int choice = getIntRange(1, 6);
        if      (choice == 1)   cout << frac1 << " + " << frac2 << " = " << frac1 + frac2;
        else if (choice == 2)   cout << frac1 << " - " << frac2 << " = " << frac1 - frac2;
        else if (choice == 3)   cout << frac1 << " * " << frac2 << " = " << frac1 * frac2;
        else if (choice == 4)   cout << frac1 << " / " << frac2 << " = " << frac1 / frac2;
        else if (choice == 5)
        {
            cout << "Enter New Fraction 1: \n";
            cin >> frac1;
            cout << "Enter New Fraction 2: \n";
            cin >> frac2;
        }
        else if (choice == 6)   keepGoing = false;
    }
    cout << "Program exiting...\n";
}