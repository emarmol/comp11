// iftest.cpp
//      purpose: report number of digits in an integer
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
	int input;

	cout << "Enter a number: ";
	cin  >> input;


	// first if statement check if the variable input is greater
	// than 100, if this is true, the program outputs that there
	// are more than three digits and that the number is positive.
	if (input >= 100) {
		cout << "input has at least three digits" << endl;
		cout << "and input is positive" << endl;
	}
	
	// if the first statement is not true, the program checks to see
	// if the number is greater than 10, and if it is true, it outputs
	// that input has two digits and is positive.
	 else if ( input >= 10) {
		cout << "input has two digits" << endl;
		cout << "and input is positive" << endl;

        // if it still is not greater than 10, but is grater than 0, it 
	// outputs that the number has one digit, and is positive
	} else if ( input >= 0) {
       	    	cout << "input has one digit" << endl;
		cout << "and input is positive" << endl;

	// if input is zero, the program outputs a string saying such
	} else if ( input == 0 ) {
		cout << "input is 0" << endl;

	// checks if number is less than or equal to -100, if true, outputs
	// that the input has three or more digits, and is negative
	} else if ( input <= -100 ) {
	    	cout << "input has three or more  digits" << endl;
		cout << "and input is negative" << endl;

	// if input is less than or equal to -10, outputs that the input
	// has two digits, and is negative
	} else if ( input <= -10 ) {
	    	cout << "input has two digits" << endl;
	    	cout << "and input is negative" << endl;

	// if input is less than or equal to 0, outputs that the inputs
	// has one digits and is negative
	} else if ( input <= 0 ) {
		    cout << "input has one digit" << endl;
		    cout << "and input is negative" << endl;
	 }
       
	 return 0;
}
