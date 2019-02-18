/*Louis Monfiero
2/5/19
Description: Program 1 generates the map that is to be used in program 2
This map creates a 9x9 array with 5 randomly distributed treasure location marked by Xs */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

#define ROWS 9
#define COLS 9

//Generates a random map and places Xs and a P into random locations
//@Param array = passes a 9x9 array
//@param size = size of array (9)
void create_map(char array[][9], int size);

//Displays Array on screen, including location of Xs and P
//@Param array = passes a 9x9 array
//@param size = size of array (9)
void display_array(char array[][9], int size);

int main()  
{
    //Initializing Variables
    char map[ROWS][COLS];
    create_map(map, 9);
    //display_array(map, 9); //simply for checking file

    fstream file;
    file.open("treasure.txt", ios::out);
    if (file)
    {
        for (int i = 0; i < 9; i++)	
        {
		    for (int j = 0; j < 9; j++)    
            { 
                file << map[i][j];
            }
            file << endl;
        }
    }
}

//Creates the map, neat-o
void create_map(char array[][9], int size)  
{
    int treasure = 0;
    int blackbeard = 0;
    srand(time(NULL));

    for (int i = 0; i < 9; i++)	
    {
		for (int j = 0; j < 9; j++)    
        {
            array[i][j] = '~';
        }
    }

    while (treasure < 5)
    {
        int i = (rand() % 9);
        int j = (rand() % 9);
        if (array[i][j] == '~')
        {
            array[i][j] = 'X';
            treasure++;
        }
    }

    while (blackbeard < 1)
    {
        int i = (rand() % 9);
        int j = (rand() % 9);
        if (array[i][j] != 'X')
        {
            array[i][j] = 'P';
            blackbeard++;
        }
    }
}

void display_array(char array[][9], int size)
{
	for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
}