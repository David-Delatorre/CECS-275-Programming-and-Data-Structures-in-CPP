#include "Point.cpp"
#include <iostream> 
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

//Gets an integer between low int and high int (inclusive)
//@param = low is the floor
//@param = high is the ceiling
//@return = user input integer between low/high
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

int mazeSelMenu()
{
	cout << "\n1. Maze #1\n2. Maze #2\n3. Maze #3\n4. Maze #4\n5. Quit\nUser Selection: ";
	int choice = getIntRange(1, 5);
	return choice;
}

int solveMenu()
{
	cout << "Choose Method to Solve Maze:\n1. DFS (Depth First Search)\n2. BFS (Breadth First Search)\n3. Do Yourself\nUser Selection: ";
	int choice = getIntRange(1, 3);
	return choice;
}

int moveMenu()
{
	cout << "1. Move Up\n2. Move Down\n3. Move Left\n4. Move Right\n5. Solve By DFS." << endl;
	int choice = getIntRange(1, 5);
	return choice;
}

vector<char> getMaze(string file, int r, int c) {
	vector<char> maze;
	int count = 0;
	fstream mazes;
	mazes.open(file, ios::in);
	char input;

	if (mazes) 
	{
		mazes >> input;
		mazes >> input;

		if (file == "maze2.txt") {
			mazes >> input;
		}
		else if (file == "maze3.txt") {
			mazes >> input;
			mazes >> input;
		}
		else if (file == "maze4.txt") {
			mazes >> input;
			mazes >> input;
		}
		//incrementers
		int total = -1;
		int counter = -1;
		int newNum = 0;
		for (int h = 0; h < c; h++) {
			c++;
			for (int w = 0; w < r; w++) {
				total++;
				newNum = c * count + count;
				while (mazes.get(input) && total != (newNum)) {
					maze.push_back(input);
				}
			}
		}
		//Closes file
		mazes.close();
	}

	for (int i = 0; i < maze.size(); i++) {
		if (maze[i] == '\n') {
			count++;
			maze.erase(maze.begin() + i);
			i = 0;
		}
	}
	return maze;
}

int getRow(string filename)
{
	fstream file;
	int row;
	file.open(filename, ios::in);
	if (file)
	{
		file >> row;
		file >> row;
		file.close();
	}

	else
	{
		cout << "\nError, no file found\n";
	}

	return row;
}

int getCol(string filename)
{
	fstream file;
	int col;
	file.open(filename, ios::in);
	if (file)
	{
		file >> col;
		file.close();
	}

	else
	{
		cout << "\nError, no file found\n";
	}
	return col;
}

int main()
{
	bool bigLoop = true;
	bool babyLoop = true;
	while (bigLoop)
	{
		int row, col;
		int mChoice = mazeSelMenu();

		//Initialize Stack/Queue with point
		stack<Point> dfs;//Stack is used for dfs
		queue<Point> bfs;//Queue is used for bfs

		//Quits function
		if (mChoice == 5)
		{
			bigLoop = false;
			break;
		}

		string mazeSel = "maze" + to_string(mChoice) + ".txt";
		row = getRow(mazeSel);
		col = getCol(mazeSel);
		cout << "Maze Dimensions: " << row << " x " << col << "\n\n";
		vector <char> mazeVec = getMaze(mazeSel, row, col);
		char mazeArr[row][col];
		int count = 0;

		cout << "You've Chosen Maze #" << mChoice << endl;
		//STORE MAZE (vector) TO ARRAY
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				mazeArr[j][i] = mazeVec[count++];
			}
		}
		//DISPLAY MAZE
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				cout << mazeArr[j][i];
			}
			cout << endl;
		}

		int solveMethod = mazeSelMenu();

		//Gets the coordinates of start point
		int startP1, startP2;
		for (int i = 0; i < col; i++)
		{
			for (int j; j < row; j++)
			{
				if (mazeArr[j][i] == 's')
				{
					startP1 = j;
					startP2 = i;
				}
			}
		}
		
		//Initialize the start point
		Point startPoint = Point(startP1, startP2);
		//Initialize new point (to be used later)
		Point point;

		//Solves the maze by DFS
		if (solveMethod == 1)
		{
			babyLoop = true;
			dfs.push(startPoint);
			while (babyLoop)
			{
				point = dfs.top();
				dfs.pop();

				if (mazeArr[point.getX()][point.getY()] == 'f')
				{
					cout << "Maze solved.\n";
					babyLoop = false;
				}

				else
				{
					//Places a . at the current point
					mazeArr[point.getX()][point.getY()] = '.';

					dfs.pop();

					//Only places points if point selected is an empty space 
					//ie not a wall *, or a point .
					//Down
					if (mazeArr[point.getX() + 1][point.getY()] != '*' && mazeArr[point.getX() + 1][point.getY()] != '.') 
					{
						dfs.push(Point(point.getX() + 1, point.getY()));
					}
					//Up
					if (mazeArr[point.getX() - 1][point.getY()] != '*' && mazeArr[point.getX() - 1][point.getY()] != '.') 
					{
						dfs.push(Point(point.getX() - 1, point.getY()));
					}
					//Right
					if (mazeArr[point.getX()][point.getY() + 1] != '*' && mazeArr[point.getX()][point.getY() + 1] != '.') 
					{
						dfs.push(Point(point.getX(), point.getY() + 1));
					}
					//Left
					if (mazeArr[point.getX()][point.getY() - 1] != '*' && mazeArr[point.getX()][point.getY() - 1] != '.') 
					{
						dfs.push(Point(point.getX(), point.getY() - 1));

					}
				}

				//DISPLAYS MAZE
			}
			for (int i = 0; i < col; i++)
			{
				for (int j = 0; j < row; j++)
				{
					cout << mazeArr[j][i];
				}
				cout << endl;
			}

		}
		//END DFS METHOD

		//Solve the maze by BFS
		else if (solveMethod == 2)
		{
			bfs.push(startPoint);
			babyLoop = true;

			while (babyLoop)
			{
				point = bfs.front();

				if (mazeArr[point.getX()][point.getY()] == 'f')
				{
					cout << "Maze solved.\n";
					babyLoop = false;
				}

				else
				{
					m[point.getX()][point.getY()] = '.';
					bfs.pop();
					if (mazeArr[point.getX() + 1][point.getY()] != '*' && mazeArr[point.getX() + 1][point.getY()] != '.') 
					{
						bfs.push(Point(point.getX() + 1, point.getY()));
					}
					if (mazeArr[point.getX() - 1][point.getY()] != '*' && mazeArr[point.getX() - 1][point.getY()] != '.') 
					{
						bfs.push(Point(point.getX() - 1, point.getY()));
					}
					if (mazeArr[point.getX()][point.getY() + 1] != '*' && mazeArr[point.getX()][point.getY() + 1] != '.') 
					{
						bfs.push(Point(point.getX(), point.getY() + 1));
					}
					if (mazeArr[point.getX()][point.getY() - 1] != '*' && mazeArr[point.getX()][point.getY() - 1] != '.') 
					{
						bfs.push(Point(point.getX(), point.getY() - 1));
					}
				}

			}
			//DISPLAY MAZE
			for (int i = 0; i < col; i++)
			{
				for (int j = 0; j < row; j++)
				{
					cout << mazeArr[j][i];
				}
				cout << endl;
			}
		}

		//END BFS METHOD

		//START DO IT YOURSELF METHOD
		else if (solveMethod == 3)
		{
			int movement = moveMenu();
			dfs.push(startPoint);
			babyLoop = true;
			while (babyLoop)
			{
				//Up
				if (movement == 1)
				{

					//if space then it is an available spot
					if (m[point.getX()][point.getY() - 1] == ' ')
					{
						y -= 1;
						m[x][y] = '.';
					}
					//if 'f' end the game and display end message
					else if (m[point.getX()][point.getY() - 1] == 'f')
					{
						cout << "WE'RE IN THE ENDGAME NOW!" << endl;
						//end and bring to MAZE MENU
						babyLoop = false;
						break;
					}

				}
				//Down
				else if (movement == 2)
				{
					//if space then it is an available spot
					if (m[point.getX()][point.getY() + 1] == ' ')
					{
						y += 1;
						mazeArr[point.getX()][point.getY()] = '.';
					}

					//if 'f' end the game and display end message
					else if (m[point.getX()][point.getY() + 1] == 'f')
					{
						cout << "WE'RE IN THE ENDGAME NOW!" << endl;
						//end and bring to MAZE MENU
						babyLoop = false;
						break;
					}
				}
				//Left
				else if (movement == 3)
				{

					//if space then it is an available spot
					if (m[point.getX() - 1][point.getY()] == ' ')
					{
						x -= 1;
						m[x][y] = '.';
					}
					//if 'f' end the game and display end message
					else if (m[point.getX() - 1][point.getY()] == 'f')
					{
						cout << "WE'RE IN THE ENDGAME NOW!" << endl;
						//end and bring to MAZE MENU
						babyLoop = false;
						break;
					}
				}
				//Right
				else if (movement == 4)
				{
					//if space then it is an available spot
					if (m[point.getX() + 1][point.getY()] == ' ')
					{
						x += 1;
						m[x][y] = '.';
					}
					//if 'f' end the game and display end message
					else if (m[point.getX() + 1][point.getY()] == 'f')
					{
						cout << "WE'RE IN THE ENDGAME NOW!" << endl;
						//end and bring to MAZE MENU
						babyLoop = false;
						break;
					}
				}

				else if (movement == 5)
				{

				}
			}

		}


		
	}
}