// add8.cpp
//      purpose: asks user for 8 floating point numbers; adds them up
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//               
//  modified by:Erika Marmol              
//         date:January 25, 2014
//
                                             
#include <iostream>

using namespace std;

int main()
{
	// creates four variables: num allows future programmers to change
	// how many numbers the user can input-currently set to 8 for problem
	// i serves as a counter for the while loop
	// sum is for the total of the numbers the user inputs
	// j is used as a variable for the numbers the user inputs
	double num = 8;
	double i = 0;
	double sum = 0;
	double j = 0;

	// prompts user to type in their numbers
	cout << "Enter " << num << " numbers: " << endl;

	// while loop using the counter variable i: sets condition if i is
	// less than num (how many numbers they can enter) the user's inputs
	// will be put in variable j, and the sum will get its current value
	// plus the number the user just inputted. i is then increased by a
	// factor of 1. Loop continues until i has reached 8 numbers
	while ( i < num ) 
	{
	    cin >> j;
	    sum = sum + j;
	    i++;
	}

	// program will output the sum of the inputted numbers
	cout << "The sum of your " << num << " numbers is: " << sum << endl;
	
	return 0;

}
