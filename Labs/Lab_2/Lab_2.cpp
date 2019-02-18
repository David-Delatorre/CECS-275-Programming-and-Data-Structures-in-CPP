/* Louis Monfiero 016336266
*  1/29/19
*  Description: 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//defining constants
#define len 10

//Prototyping Functions
//Input validation; Checks if input is a digit
//@return = returns user input with input validation (no letters)
int getInt(); 

//Populates the Array by prompting the user to input 10 integers into array in the order input-ted
//@param = array; array containing 10 numbers that will be input-ted by the user 
//@param = size; length/size of the array (10)
void popArray(int array[], int size);

//Contents of Array will be printed out in the order they were input-ted
//@param = array; array containing 10 numbers that will be input-ted by the user
//@param = size ; length/size of the array (10)
void printValue(int array[], int size);

//Contents of Array will be printed in reverse order
//@param = array; array containing 10 numbers that will be input-ted by the user
//@param = size ; length/size of the array (10)
void printReverse(int array[], int size);

//Prompts user to enter a value; function will find if value is in the array
//@param = array; array containing 10 numbers that will be input-ted by the user
//@param = size; length/size of the array (10)
//@param = search; input in main() by user; function will check if this value is in the array
//@return = returns value that is found
int findValue(int array[], int size, int search);

//Prompts user to enter an index and a value; function will replace value of said index in the array
//@param = array; array containing 10 numbers that will be input-ted by the user
//@param = location; input by a user in main(); chooses index location of value you want to replace
//@param = newNum; the new number you want to replace it with
void insertValue(int array[], int location, int newNum);

//Finds the highest value in the array
//@param = array; array containing 10 numbers that will be input-ted by the user
//@param = size ; length/size of the array (10)
//@returns max value of array
int maxValue(int array[], int size);

//Adds all the values from the array and computes the sum
//@param = array; array containing 10 numbers that will be input-ted by the user
//@param = size ; length/size of the array (10)
//@return = returns sum of all numbers
int getSum(int array[], int size);

//Shows a menu with 8 options to choose
void showMenu();


int main()	{
	bool loop = true;
	//Initializing variables;
	int list[len];
	int search = 0;
	int newNum = 0;
	int find = 0;
	int choice = 0;
	int max = 0;
	int found = 0;
	int sum = 0; 
  
	popArray(list, len);

	while(loop)	{
		showMenu();
		choice = getInt();

		if (choice == 1)	{
			printValue(list, len);
		}

		else if (choice == 2)	{
			printReverse(list, len);
		}

		else if (choice == 3)	{
			sum = getSum(list, len);
			cout << "Sum of the array is: " << sum << endl;
		}
		
		else if (choice == 4)	{
      max = maxValue(list, len);
			cout << "Max Value is: " << max << endl;
		}

		else if (choice == 5)	{
      cout << "What value are you looking for? ";
			search = getInt();
			found = findValue(list, len, search);
			if (found != -1) cout << "Value is located at index: " << found << endl;
      else cout << "Value not found" << endl;
		}

		else if (choice == 6)	{
			insertValue(list, find, newNum);
      cout << "Your new array is: ";
      printValue(list, len);
		}

		else if (choice == 7) 	{
			popArray(list, len);
      cout << "Your new array is: ";
      printValue(list, len);
		}

		else if (choice == 8)	{
			cout << "Thank you! Have a nice day!" << endl;
			loop = false;
		}
	}

  cin.get();
}

int getInt( ) {
	int input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			valid = true;
		} else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout<< "Invalid. Try again: ";
		}
	}
	return input;
}

//Populates Array with any integer that is input by the user in the order typed
void popArray(int array[], int size)	
{
	for (int i = 1; i < size + 1; i++)	{
		cout << "Enter value #" << i << ": ";
		array[i] = getInt();
	}
}

//Prints out the array in order
void printValue(int array[], int size)	{
	for (int i = 1; i < size + 1; i++) {
		cout << array[i];
		if (i != size) cout << ", ";
  }
  cout << endl;
}

//Prints the array in reverse order
void printReverse(int array[], int size)	{
	for (int i = size; i > 0; i--)	{
		cout << array[i];
		if (i != -1) cout << ", ";
	}
  cout << endl;
}

//Searches array for the value the user inputs
int findValue(int array[], int size, int search)	{
	for (int i = 0; i < size + 1; i++)	{
		if (array[i] == search)	{
			return i;
		}
	}
	return -1;
}

//Replaces the value at specified index
void insertValue(int array[], int location, int newNum)	{
  bool loop = true;
  cout << "Choose an index to replace: ";
  while (loop) {
    location = getInt();
    if ((location > 0) and (location < 11))  {
      loop = false;  }
    else {
      cout << "Choose a valid index (1-10) to replace: ";
    }
  }
  cout << "Choose a new number to replace it with: ";
	newNum = getInt();
  array[location] = newNum;
}

//Finds largest value in the array
int maxValue(int array[], int size)	{
	int max = 0;
	for (int i = 1; i < size + 1; i++)	{
		if (array[i] > max) max = array[i];
	}
	return max;
}

//Adds all numbers to get the sum
int getSum(int array[], int size)	{
	int total = 0;

	for (int i = 1; i < size + 1; i++)	{
    total += array[i];
	}
	return total;
}

//Prints out the menu
void showMenu()	{
	cout << "\n1. Display Values \n2. Display Reversed \n3. Display Sum \n4. Display Maximum \n5. Search for a Value \n6. Insert New Value \n7. Reset Values \n8. Quit \nSelect Value: ";
}