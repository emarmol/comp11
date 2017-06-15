//
// avg2.cpp -- compute average of three numbers
//             demonstrates:
//		  input, output
//		  variables, assignment
//		  operations: +, / with ints, %, / with floats
//		  comments
// modified by:Erika Marmol
//          on:January 23, 2014
//

#include <iostream>

using namespace std;

int main()
{
	int	sum;		// sum goes here
	int	quotient;
	int	remainder;
	int	num;
	int	x;
	x=0;
	sum=0;
	cout  << "How many numbers?" << endl;
	cin   >>  num;		// number of values to average

	cout << "Please enter numbers: ";

	while (x<num+1)
	{
		cin >> x;
		sum = sum + x;
		x++;
	}

	// do the processing part now

	quotient  = sum / num;
	remainder = sum % num;

	// output the result

	cout << "The average is " << quotient << " " ;
	cout << remainder << "/" << num << endl;
	cout << "In decimal form: " << (sum / num) << endl;
}
