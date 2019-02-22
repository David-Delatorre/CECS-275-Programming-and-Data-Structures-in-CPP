/* Recursion2.cpp
 Louis Monfiero
 016336266 
 Lab 4
 Descr: Use 4 skeleton functions and write own code into it
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int maxArray(int array[], int size, int i, int max );
int minArray( int array[], int size, int i, int min );
int charFrequency(string str, char c);
string reverseStr(string s);
int findMax(int array[], int max);
int findMin(int array[], int min);


/* Finds the maximum value in an array
 * @param array array of values (sorted or unsorted)
 * @param size length of the array
 * @param i iterator
 * @param max maximum value found so far
 * @return maximum value
 */


int maxArray(int array[], int size, int i, int max ) 
{
    if (i != size)
    {
        if (max < array[i])
        {
            max = array[i];
        }
        return maxArray(array, size, i + 1, max);
    }
    //cout << max;
    return max;
}

/* Finds the minimum value in an array
 * @param array array of values (sorted or unsorted)
 * @param size length of the array
 * @param i iterator
 * @param min minimum value found so far
 * @return minimum value
 */
int minArray( int array[], int size, int i, int min ) 
{
    // min = array[i];
    if (i != size)
    {
        if (min > array[i])
        {
            min = array[i];
        }
        return minArray(array, size, i + 1, min);
    }
    //cout << min;
    return min;
}

/* Reverses a string
 * @param s the string to reverse
 * @return the reversed string
 */
string reverseStr( string s ) 
{
    if (s.length() > 0)
    {
        int len = s.length() - 1;
        //cout << s << endl;
        return s[len]+reverseStr(s.substr(0, len));
    }
    return s;
}

/* Returns the number of times c appears in the string str
 * @param str string to test
 * @param c character to find
 * @return number of times the character appeared in the string
 */
int charFrequency( string str, char c ) 
{	
    int len = str.length() - 1;
    if (str.length() > 0)
    {
        if (str[0] != c)
        {
            return charFrequency(str.substr(1, len), c);
        }
        return 1 + charFrequency(str.substr(1, len), c);
    }
    return 0;
}

//Write your facade functions findMin & findMax here
int findMax(int array[], int size)
{
    return maxArray(array, size, 0, 0);
}

int findMin(int array[], int size)
{
    return minArray(array, size, 0, array[0]);
}

int main( ) {
	int array [] = { 46, 22, 7, 58, 91, 55, 31, 84, 12, 78 };
	if( findMax( array, 10 ) == 91 ) {
		cout<< "findMax is correct!" <<endl;
	}
	if( findMin( array, 10 ) == 7 ) {
		cout<< "findMin is correct!" <<endl;
	}
	if( reverseStr( "Hello" ) == "olleH" ) {
		cout<< "reverseString1 is correct!" <<endl;
	}
	if( reverseStr( "pupils" ) == "slipup" ) {
		cout<< "reverseString2 is correct!" <<endl;
	}	
	if( charFrequency( "The quick brown fox jumps over the lazy dog.", 'o' ) == 4 ) {
		cout<< "charFrequency1 is correct!" <<endl;
	}
	if( charFrequency( "The quick brown fox jumps over the lazy dog.", 'e' ) == 3 ) {
		cout<< "charFrequency2 is correct!" <<endl;
	}

}