#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


void loadGrid(char array[][10], string filename);
int getChoice();
void displayGrid(char array[][10]);
void traverse(char array[][10]);
int recursive(char array[][10], int james, int bay, int c, int YUH, int yeet);


int main()
{
    char gridAr[10][10];
    int choice;
    string gridChoice;
    choice = getChoice();
    gridChoice = "grid"+to_string(choice)+".txt";
    loadGrid(gridAr, gridChoice);
    displayGrid(gridAr);
    traverse(gridAr);


    return 0;
}

void loadGrid(char array[][10], string filename)
{
    int ccounter = 1;
    int rcounter = 1;
    fstream file;
    string line;
    file.open(filename, ios::in);
    for (int k = 0; k < 10; k++) 
        {
            for (int j = 0; j < 10; j++)
            {
                array[k][j] = '#';
            }
        }

    if (file)
    {
        while(getline(file, line))
        {   
            for (int i = 0; i < line.length(); i++)
            {   
                if (ccounter == 9)
                {
                    rcounter++;
                    ccounter = 1;
                }
                array[rcounter][ccounter] = line[i];
                ccounter++;
            }
        }
        file.close();
    }
    else
    {
        cout << "File not found" << endl;
    }
}

int getChoice( ) {
	int input = 0;
	bool valid = false;
    cout << "Select Grid #: ";
	while(!valid) {
		if(cin >> input) 
        {
		    valid = true;
		} 
        else 
        {
			cin.clear(); 
			string invalid;
			cin >> invalid;
			cout<< "Please enter a valid number: ";
		}
	}
	return input;
}

void displayGrid(char array[][10])
{
    for (int i = 1; i < 9; i++) 
    {
        for (int j = 1; j < 9; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
}

void traverse(char array[][10])
{
    int count = 0;
    int area = 0;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++)
        {
            if (array[i][j] == 'o')
            {
                count = recursive(array, i, j, 0, j, i + 2);
                area++;
                cout << "Area " << area << " size is: " << count << endl;
                //displayGrid(array);
            }
        }
        // if (count != 0)
        // {
        //     cout << "Area " << area << " size is: " << count << endl;
        //     displayGrid(array);
        //     cout << endl;
        //     count = 0;
        // }
    }
}

int recursive(char array[][10], int james, int bay, int c, int YUH, int yeet)
{
    if (array[james][bay] == 'o')
    {
        c++;
        if (array[james + 1][bay] == 'o')
        {
            c++;
            array[james + 1][bay] = '#';
        }
        if (array[james - 1][bay] == 'o')
        {
            c++;
            array[james - 1][bay] = '#';
        }
        if (array[james][bay - 1] == 'o')
        {
            c++;
            array[james][bay - 1] = '#';
        }
        if (array[james][bay + 1] == 'o')
        {
            if (array[james - 1][bay + 1] == 'o')
            {
                c++;
                array[james - 1][bay + 1] = '#';
            }
            if (array[james + 1][bay + 1] == 'o')
            {
                c++;
                array[james + 1][bay + 1] = '#';
            }
        }
        
        array[james][bay] = '#';
        return recursive(array, james, bay + 1, c, YUH, yeet);
    }
    if (array[yeet][YUH] == 'o')
    {
        c++;
        if (array[yeet + 1][YUH] == 'o')
        {
            if (array[yeet + 1][YUH + 1] == 'o')
            {
                //c++;
                array[yeet + 1][YUH + 1] = '#';
            }
            if (array[yeet - 1][YUH + 1] == 'o')
            {
                c++;
                array[yeet - 1][YUH + 1] = '#';
            }
            c++;
            array[yeet + 1][YUH] = '#';
        }
        if (array[yeet - 1][YUH] == 'o')
        {
            if (array[yeet - 1][YUH - 1] == 'o')
            {
                c++;
                array[yeet - 1][YUH - 1] = '#';
            }

            if (array[yeet - 1][YUH + 1] == 'o')
            {
                c++;
                array[yeet - 1][YUH + 1] = '#';
            }
        }
        if (array[yeet][bay - 1] == 'o')
        {
            c++;
            array[yeet][YUH - 1] = '#';
        }
        if (array[yeet][YUH + 1] == 'o')
        {
            c++;
            array[yeet][YUH + 1] = '#';
        }
        
        array[yeet][YUH] = '#';
        return recursive(array, james, bay, c, YUH, yeet + 2);
    }
    return c;
}