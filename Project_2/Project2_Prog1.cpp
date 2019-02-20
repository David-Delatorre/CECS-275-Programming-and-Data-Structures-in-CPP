/*Louis Monfiero
2/5/19
Description: Program reads a grid from a text file named 'Grid#.txt' 
and places the grid into the middle of a 10x10 array
The grid is then displayed to the user in an 8x8 array
and counts the number of consecutive O's (left, right, up, or down)
and returns the number of o's per area. The rest of the array
is populated with #s
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


//input validation
//@returns an integer number
int getInt();

//reads the grid found in file grid#.txt and copies the contents into the center of a 10x10 array populated
//with #s
//@param = passes a 10x10 array
//@param = passes in a string containing the name of the file to be read
void readGrid(char array[][10], string filename);

//displays the 8x8 grid inside the 10x10 grid
//@param = passes in an array to be populated by the grid
void displayGrid(char array[][10]);

//checks each spot in the array to see if it spots a letter o
//if an o is spotted, the function areaCount is called in to count the number of 
//consecutive Os spotted and how many different sections of Os there are
//@param = passes the 10x10 array and checks it for Os
void traverse(char array[][10]);

//recursive function that counts how many Os are in the array passed
//checks right, then left, then up, and then down
//recursively calls itself to check adjacent locations for Os
//@param array = passes in the 10x10 array to be read
//@param x = rows
//@param y = columns
//@param c = count the number of Os spotted
//@return = returns the amount of Os spotted in a given area/section
int areaCount(char array[][10], int x, int y, int c);



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
        cout << "If an item does not appear in our records, then it does not exist." << endl;
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
			cout<< "Please try again (a number): ";
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

//checks grid for an O from array[1][1] to array[9][9]
void traverse(char array[][10])
{
    int count = 0;
    int area = 1;
    for (int i = 1; i < 9; i++) 
    {   
        for (int j = 1; j < 9; j++)
        {
            if (array[i][j] == 'o')
            {
                count = areaCount(array, i, j, count);
                cout << "Area " << area << " size = " << count << endl;
                area++;
                count = 0;
            }
            
        }
    }
}

//row = x; col = y; c = count;
//change found os to #
//checks right and if it is an o, increments c;
//after checking right, it will recursively continue to check right until no more Os are found
//when there is no more Os, it will check the left side until no more Os are found
//there is no double counting as any found O is replaced with a #
//after going left, it will then go up, and then lastly down
//after finally counting the amount of Os, it returns the amount of Os spotted
int areaCount(char array[][10], int x, int y, int c)
{
    
    if (array[x][y] == 'o')
    {
        array[x][y] = '#';
        c++;
        //cout << x << " " << y << " " << c << endl;
        c = areaCount(array, x, y + 1, c);//check right 
        c = areaCount(array, x, y - 1, c);//check left
        c = areaCount(array, x + 1, y, c);//check up
        c = areaCount(array, x - 1, y, c);//check down
        //cout << c << endl;
        return c;
    }
    return c;
    
}