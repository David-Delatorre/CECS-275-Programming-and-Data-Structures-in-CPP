/* Louis Monfiero 016336266
*  1/22/19
*  Description: Generate a random number 1-100; keeps user inputting a number until number is guessed correctly
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Input validation; Checks if input is a digit
int getInt();

int main() 
{
  int input = 0;
  int tries = 1;
  srand(time(NULL));
  int answer = (rand() % 100 + 1);
  cout << "I'm thinking of a number. Guess a value (1-100): ";

  while (1)
  {
    input = getInt();
    
    if ((input < answer) && ((input <= 100) && input > 0))
    {
      cout << "Too Low. Guess again: ";
      tries++;
    }
    
    else if ((input > answer) && ((input <= 100) && input > 0))
    {
      cout <<"Too High. Guess again: ";
      tries++;
    }

    else if (input == answer)
    {
      cout << "Correct! You got it in " << tries << " tries!" << endl;
      tries++;
      break;
    }

    else 
    {
      cout << "Invalid. Try again: ";
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