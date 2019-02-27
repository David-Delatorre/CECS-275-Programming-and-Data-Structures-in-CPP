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

int * populate(int size);
void display(int *ptrArray, int size);
// void swap(int num1, int num2);
// void sort(int array[], int size);
// void shuffle(int array[], int size);
// int max(int array[], int size);
int GetPositiveInt();
int GetIntRange(int low, int high);
void menu();


int main()
{
    menu();
    int arraySize;
    arraySize = GetPositiveInt();
	int *ptrArray;
    ptrArray = populate(arraySize);
	display(ptrArray, arraySize);





    return 0;
}

int * populate(int size)
{
    srand(time(NULL));
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % 100 + 1);
    }
    return array;
}

void display(int *ptrArray, int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if ((i - size) != 0) cout << ptrArray[i] << ", ";
        else cout << ptrArray[i];
        
        counter++;
        if (counter == 10)
        {
            counter = 0;
            cout << endl;
        }
    }
}

// void swap(int num1, int num2)
// {
//     //code
// }

// void sort(int array[], int size)
// {
//     //code
// }

// void shuffle(int array[], int size)
// {
//     //code
// }

// int max(int array[], int size)
// {
//     //code
// }

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
