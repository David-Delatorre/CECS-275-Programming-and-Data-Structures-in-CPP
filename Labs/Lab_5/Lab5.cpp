/*Lab 5.cpp
 Louis Monfiero
 016336266 
 2/26/19
 Descr: Introduction to pointers; Use pointers to arrays to manipulate an array
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//Descr: dynamically populates an array with the amount input by a user
//@param = Passes in a size (inputted by the user) of said array
//@return = returns array of randomized numbers (1 - 100)
int * populate(int size);

//Descr: displays array of numbers (10 per row)
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
void display(int *ptrArray, int size);

//Descr: goes into an array and swaps 2 numbers; used by sort() and shuffle()
//@param = passes in pointer to integer one to swap
//@param = passes in pointer to integer 2 to swap
void swap(int *num1, int *num2);

//Descr: goes into an array and uses the swap function using selection sort
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
void sort(int *ptrArray, int size);

//Descr: shuffles numbers in array to random locations in said array
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
void shuffle(int *ptrArray, int size);

//Descr: finds the largest number in an array
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
//@return = returns the largest number in an array
int max(int *ptrArray, int size);

//Descr: input validation; user can only input a positive integer
//@return = returns a positive integer input by the user 
int GetPositiveInt();

//Descr: input validation; user can only input an integer between two points (low and high)
//@param = low - floor range value
//@param = high - ceiling range value
//@return = returns integer input by the user
int GetIntRange(int low, int high);

//Descr: displays the menu (options 1 to 5)
void menu();

int main()
{
	int choice = 0;
	int *ptrArray;
	cout << "Enter array size: ";
    int arraySize = GetPositiveInt();
    ptrArray = populate(arraySize);

	while (choice != 5)
	{
		menu();
		choice = GetIntRange(1, 5);
		if (choice == 1) 		display(ptrArray, arraySize);
		else if (choice == 2)	sort(ptrArray, arraySize);
		else if (choice == 3)	shuffle(ptrArray, arraySize);
		else if (choice == 4)	cout << "Maximum number is: " << max(ptrArray, arraySize);
		else if (choice == 5)	cout << "Program Exiting...\n";
	}

    return 0;
}

//populates an array with a size input by the user
int * populate(int size)
{
    srand(time(NULL));
    int* array = new int(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % 100 + 1);
		//cout << "\n" << array[i];
    }
    return array;
}

//displays the array to the user
void display(int *ptrArray, int size)
{
    int counter = 0;
	//cout << "test";
    for (int i = 0; i < size; i++)
    {
        if ((i + 1) != size) cout << ptrArray[i] << ", ";
        else cout << ptrArray[i];
        
        counter++;
        if (counter == 10)
        {
            counter = 0;
            cout << endl;
        }
    }
}

//swaps two integers; used by sort and shuffle
void swap(int *num1, int *num2)
{
    int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//sorts values in array from lowest to highest
void sort(int *ptrArray, int size)
{
	int min;
    for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (ptrArray[j] < ptrArray[min])	min = j;
		}
		swap(&ptrArray[min], &ptrArray[i]);
	}
}

//shuffles values in the array several times
void shuffle(int *ptrArray, int size)
{
	srand(time(NULL));
	int ind1, ind2;
    for (int i = 0; i < size*10; i++)
	{
		ind1 = (rand() % size);
		ind2 = (rand() % size);
		swap(&ptrArray[ind1], &ptrArray[ind2]);
	}
}

//finds and returns largest value in the array
int max(int *ptrArray, int size)
{
	int maximum = 0;
	for (int i = 0; i < size; i++)
	{
		if (maximum < ptrArray[i])
		{
			maximum = ptrArray[i];
		}
	}
	return maximum;
}

//prompts user to enter a positive integer
int GetPositiveInt()
{
    int input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			if(input >= 0) {
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

//Input validation; in the case of main, we used this for selecting between 1, 2, 3, 4, and 5
int GetIntRange(int low, int high)
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

//prints out menu and options
void menu()
{
    cout << "\n1. Display\n2. Sort\n3. Shuffle\n4. Max\n5. Quit\n";
}
