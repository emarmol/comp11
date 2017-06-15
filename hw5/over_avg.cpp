/* Name: Erika Marmol
   Date: 2/24/2014
   Title: over_avg.cpp
   Description: calculates average, and sees how many of the numbers
		were greater than the average. Returns that number.
*/

#include <iostream>

using namespace std;

const int SPACE = 30000;
const int SENTINEL = 0;

double average( int nums[]);
double num_avgs( double avg, int nums[SPACE]); 

// creates the array for the years, and checks to see
// if more data is inputted than there is space
int main()
{
    int num = 0;
    int pos = 0;
    int years[SPACE];
    int total = 0;

    do {
	cin >> num;
	years[pos++] = num;
	if (pos > SPACE)
	{
	    cerr << "too much input" << endl;
	    return 1;
	}

    } while (num != SENTINEL);

	total = average(years);

    cout << total << endl;

    return 0;
}

// stores the running total, and calculates the average
// passes the average to the next function, returns
// a double
double average( int nums[SPACE])
{
    int pos = 0;
    double curr = 0.0;
    double avg = 0.0;
    double ANS = 0.0;

    while (nums[pos] != SENTINEL) {
	curr = curr + nums[pos];
	pos++;
    }

    avg = curr/(pos);
    ANS = num_avgs(avg, nums);
    return ANS;
}


// checks to see if the average is larger than each number in
// the array. Counter changes if the number is larger
// returns a double.
double num_avgs( double avg, int nums[SPACE])
{
    double counter = 0.0;
    int pos = 0;
    while (nums[pos] != SENTINEL) {

    	if (avg < nums[pos])
    	{
		counter++;
    	}
	pos++;
    }
    return counter;
}
