/* Name: Erika Marmol
   Date: 2/24/14
   Title: avg_age.cpp
   Description: searches for inputted name to see extra date of birth
 		will return the average age of all people listed in
		the database, and will say if the person is not listed.
*/

#include <iostream>

using namespace std;

const int SENTINEL = -1;
const int SPACE = 50000;
const string DONE = "DONE";

double average_age(string people[], int ages[], string person);
double average(double age, int counter);

// creates the two arrays to store the years and the names
// reads in the name, and calls the next function
int main()
{
	string name = "";
	int pos = 0;
	int ages[SPACE];
	string people[SPACE];
	string person= "";
	int year;
	double final_avg = 0;
	do {
	    if (pos >= SPACE)
	    {
		cerr << "too much data" << endl;
		return 1;
	    }
	    cin >> year;
	    ages[pos] = year;
	    cin >> name;
	    people[pos] = name;
	    pos++;
	} while (year != SENTINEL);

	cout <<"Enter a name: " << endl;
	cin >> person;

	final_avg = average_age(people, ages, person);

	if (final_avg > 0)
	{
	cout << "average age = " << final_avg << endl;
	}
    return 0;
}

// searches for the name, and if the name is the same as the inputted
// one the position is extracted, and reads the year at that instance
// Year is subtracted from current year and passed to the next function
// to be averaged --running total of ages are divided by a counter
// that keeps track of how many people are listed with the name
double average_age(string people[SPACE], int ages[SPACE], string person)
{
    int pos = 0;
    double age = 0;
    int counter = 0;
    double total = 0;

        while (ages[pos] != SENTINEL)
    	{	
	    	while (people[pos] != DONE)
		{
		    if (people[pos] == person)
		    {
			age = age + (2014-ages[pos]);
		        counter++;
		    }
  		    pos++;
		}
    	}

	if (counter == 0)
	{
	    cout << "name not found" << endl;
	}
    total = average (age, counter);
    return total;
}

// averages the age of the people. Returns a double
double average(double age, int counter)
{

    double avg = 0;
    avg = age/counter;
    return avg;
}
