#include <iostream>
#include <string>
#include "stack.h"
using namespace std; 

//Grabs input from floor to ceiling
//@param low = floor
//@param high = ceiling
//@return user input integer between low and high
int getIntRange(int low, int high) {
	int input = 0;
	bool valid = false;
	while (!valid) {
		if (cin >> input) {
			if (input >= low && input <= high) {
				valid = true;
			}
			else {
				cout << "Invalid Input" << endl;
			}
		}
		else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout << "Invalid Input" << endl;
		}
	}
	return input;
}

//Fills the array with a '.'
//@param = passes in array to be filled with '.'
void fill(char array[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			array[i][j] = '.';
		}
	}
}

//Prints out contents of array
//@param = passes in array to be displayed
void print(char array[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << array[i][j];
		}
		cout << endl;
	}
}

//Checks to see if you the area can be overwritten
//@param array = array to be written into
//@param p = point object
//@param c = counter
void check(char array[5][5], Point p, int c)
{
	int x = p.getX();
	int y =	p.getY();
	char val = '0' + c; 
	array[y][x] = val;
	if (x - 1 >= 0)     array[y][x - 1] = val;
	if (x + 1 <= 4)     array[y][x + 1] = val;
	if (y - 1 >= 0)     array[y - 1][x] = val;
	if (y + 1 <= 4)     array[y + 1][x] = val;
}

int main()
{
	Stack points;
	char field[5][5];
	fill(field);
	int count = 1;
	int x;
	int y;
	cout << "Enter point 5 Points:\n";
	while (count <= 5)
	{
		x = getIntRange(0, 4);
		y = getIntRange(0, 4);
		Point point(x, y);
		points.push(point);
		field[y][x] = '0' + count;
		count++;
	}
	count = 5;
	
    while (count >= 1)
	{
		check(field, points.pop(), count);
		count--;
	}
	print(field);
}