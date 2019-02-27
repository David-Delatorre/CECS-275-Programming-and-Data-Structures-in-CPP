/*Lab 5.cpp
 Louis Monfiero
 016336266 
 2/26/19
 Descr: idk yet
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//Descr:
//@param = Passes in a size (inputted by the user) of said array
int * populate(int size);

//Descr:
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
void display(int *ptrArray, int size);

//Descr:
//@param = 
void swap(int num1, int num2);

//Descr:
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
void sort(int *ptrArray, int size);

//Descr:
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
void shuffle(int *ptrArray, int size);

//Descr:
//@param = Passes in a pointer to an array
//@param = Passes in a size (inputted by the user) of said array
int max(int *ptrArray, int size);

//Descr:
//@param = 
int GetPositiveInt();

//Descr:
//@param = 
int GetIntRange(int low, int high);

//Descr:
//@param = 
void menu();



int main()
{
	int choice = 0;
	int *ptrArray;
	// bool loop = true;
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

void swap(int *num1, int *num2)
{
    int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

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

void menu()
{
    cout << "\n1. Display\n2. Sort\n3. Shuffle\n4. Max\n5. Quit\n";
}
