//Name: Erika Marmol
// Date: 2/24/14
// Description: Averages numbers inputted
// read_years.cpp - demo of sentinel
//

#include <iostream>
using namespace std;

const int SPACE    =  1000;
const int SENTINEL = -1;

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Interfaces  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void   print_seq(int nums[]);

// returns the average (mean) value
// of the integers in the sequence
double average  (int nums[]);


/////////////////////////////////////////////////////////////////////////
/////////////////////////////   Client  /////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main()
{
        int years[SPACE];
        int pos = 0;
        int y;
        double avg;

        do {
                cin >> y;
                years[pos++] = y;
		if (pos > SPACE)
		{
		    cerr << "too much input" << endl;
		    return 1;
		}
        } while (y != SENTINEL);
	
        print_seq(years);
        avg = average(years);
        cout << "avg = " << avg << endl;
	
        return 0;
}

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Abstraction ///////////////////////////////
///////////////////////////     Barrier   ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

//////////////////////////  Implementations /////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void print_seq(int nums[SPACE])
{
        int pos = 0;
        while (nums[pos] != SENTINEL) {
                cout << pos << " " << 
	        nums[pos] << endl;
                pos++;
        }
}

// returns the average (mean) value
// of the integers in the sequence
double average(int nums[SPACE])
{

      int pos = 0;
      double curr = 0.0;
      double avg = 0.0;
      while (nums[pos] != SENTINEL) {
	     curr = curr + nums[pos];
             pos++;
      } 
      avg = curr/pos;
        return avg;
}
