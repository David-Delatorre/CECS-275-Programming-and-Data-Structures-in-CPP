#include "point.cpp"
#include <iostream> 
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//Gets an integer between low int and high int (inclusive)
//@param = low is the floor
//@param = high is the ceiling
//@return = user input integer between low/high
int getIntRange(int low, int high) {
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

int mazeSelMenu()
{
    cout << "\n1. Maze #1\n2. Maze #2\n3. Maze #3\n4. Maze #4\n5. Quit\n";
    int choice = getIntRange(1, 5);
    return choice;
}

int solveMenu()
{
    cout << "Choose Method to Solve Maze:\n1. DFS (Depth First Search)\n2. BFS (Breadth First Search)\nUser Selection: ";
    int choice = getIntRange(1, 2);
    return choice;
}

int main()
{
    bool bigLoop = true;
    while(bigLoop)
    {
        int row, col;
        int mChoice = mazeSelMenu();
        string maze = "maze"+to_string(mChoice)+".txt";
    }
}