/*Louis Monfiero
2/5/19
Description: etc.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


int getInt();
void readGrid(char array[][10], string filename);
void displayGrid(char array[][10]);
void traverse(char array[][10]);
int areaCount(char array[][10], int x, int y, int i);



int main()
{
    //Passes grid into gridAr
    char gridAr[10][10];
    string gridName;
    int choice;
    choice = getInt();
    gridName = "grid"+to_string(choice)+".txt";
    readGrid(gridAr, gridName);
    displayGrid(gridAr);
    traverse(gridAr);


    return 0;
}

void readGrid(char array[][10], string filename)
{
    int ccounter = 1;
    int rcounter = 1;
    for (int k = 0; k < 10; k++) 
    {   
        for (int j = 0; j < 10; j++)
        {
            array[k][j] = '#';
        }
        cout << endl;
    }
    
    fstream file;
    string line;
    file.open(filename, ios::in);
    if (file)
    {
        while(getline(file, line))
        {   
            for (int i = 0; i <= line.length(); i++)
            {   
                if (ccounter == 9)
                {
                    rcounter++;
                    ccounter = 0;
                }
                array[rcounter][ccounter] = line[i];
                ccounter++;
            }
        }
        //cout << "File read successfully\n";
        file.close();
    }
    else
    {
        cout << "File not found" << endl;
    }
    
}


int getInt( ) 
{
	int input = 0;
	bool valid = false;
    cout << "Enter Grid #: ";
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
			cout<< "Please enter a valid number (1 - 9): ";
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
    int area = 1;
    for (int i = 0; i < 10; i++) 
    {   
        for (int j = 0; j < 10; j++)
        {
            if (array[i][j] == 'o')
            {
                count = areaCount(array, i, j, count);
                cout << "Area" << area << " = " << count << endl;
                area++;
                count = 0;
            }
        }
    }
}

//row = x; col = y; size = area size; i = count;
//change found os to #
int areaCount(char array[][10], int x, int y, int c)
{
    if (array[x][y] == '#')
    {
        return 0;
    }
    
    c++;
    array[x][y] = '#';
    areaCount(array, x, y + 1, c);//check right 
    areaCount(array, x, y - 1, c);//check left
    areaCount(array, x + 1, y, c);//check up
    areaCount(array, x - 1, y, c);//check down
    return c;
}