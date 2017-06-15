/* Name: Erika Marmol
   Date: February 14, 2014
   Title: diag.cpp
   Description: user inputs how many lines long the pattern will be, and the
		program outputs an increasing pattern of X's.
*/

#include <iostream>

using namespace std;

// declares two functions used in program after main()
void draw_picture(string w1, string w2, int hgt);
string reps(string first, int numtimes);


// main asks user for the height, first and second strings to be passed into
// the void function draw_pictures() taking all three as parameters
int main()
{

    string s1, s2;
    int height = 0;

    cout << "First string? ";
    cin >> s1;

    cout << "Second string? ";
    cin >> s2;

    cout << "Height? ";
    cin >> height;

    draw_picture(s1, s2, height);

    return 0;
}

// void function within while loop to print out as many times as the user's
// inputted height. Uses if statement to ensure the counter, j, is greater
// than 0 before printing the string w2. Checks if height is greater than 1
// in loop, which is decrementing by 1 each time. If so, calls function reps
void draw_picture(string w1, string w2, int hgt)
{

    string total = w2;
    int j=0;
    int count=hgt;

	while (j<count)
	{
	    if (j>0)
	    {
		cout << total;
		total = total + w2;
	    }

	    if (hgt >1)
	    {
	    cout << reps (w1, hgt);
            hgt --;
	    }

	    j++;
	    cout << endl;
	}    
}

// function returns a string, with the purpose of being a loop to repeat the
// number of times each character must be repeated to print out on each line
//one less character than the height given. Returns the string first, which 
// is w1, or the first string inputted.
string reps (string first, int numtimes)
{

    int counter=0;

    while ( counter < numtimes - 2)
    {
	cout << first;
	counter++;
    }

    return first;
}
