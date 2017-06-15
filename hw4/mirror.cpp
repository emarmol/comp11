/* Name: Erika Marmol
   Date: February 14, 2014
   File: mirrors.cpp
   Description: User will input a maximum number, and the program will
		count up to the number, and mirror the sequence counting
		back down to 0.
*/

#include <iostream>

using namespace std;

// declares the void function used later in the program
void countup(int num);

// main function which promps the user to input a maximum number, reads input
// and calls the void functions countup with the parameter of the maxnum given
int main()
{

    int maxnum;

    cout << "Maximum value?" << endl;
    cin >> maxnum;

    countup(maxnum + 1);
    return 0;
}


// void function with a while loop to print out the sequence four times
// two counters to keep track of the countup and the countdown. while loop
// for each countup and down with respective incrementing/decrementing for 
// up and down. All inside if statement for if num > 0 to prevent from
// any output being printed for negative numbers, else it ends the program
void countup(int num)
{
    int loop = 0;

    while (loop < 4)
    {
	if ( num > 0 )
	{
                int counter = 0;
       		int counter2=num-1;

	        while (counter < num)
	        {
			cout << counter;
			counter++;
	        }

    		cout << "|";

	        while (counter2 > -1)
	        {
			cout << counter2;
			counter2--;
      	        }

       	         cout << endl;
       		 loop++;
	}
	
	else
	{
		break;
	}
    }
}
