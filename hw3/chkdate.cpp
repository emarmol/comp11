/*chkdate.cpp -- program to determine if a date entered is valid (an actual day)
usage: ./chkdate2
input: three dates ( month, day, year)
output: Y or N depending of if the day exists
modified by: Erika Marmol
modified on: February 4, 2014                                                                                                 
*/

#include <iostream>

using namespace std;

//creates constants for each month
const int JAN=1, FEB=2, MAR=3, APR=4, MAY=5, JUN=6, JUL=7, AUG=8, SEPT=9, OCT=10, NOV=11, DEC=12;


// function containing if statements to depending on the validity of the month entered (between 1 and 12),
// the day (depends on the month entered: whether 30 or 31, unless it's February*), and the year (ranging
// between the years 1 and 9999)
// *February is different to take into account leap years (decides whether the month is 28 or 29 days long
// if statements are used so that if the condition is or is not met, the terminal will output a Y or N
int main()
{
    int  mon, dte, yr;             // input values                             

    cin >> mon >> dte >> yr;      // read in three values                 

    if ((mon < JAN) || (mon > DEC))
    {
	cout << "N" << endl;
    }

    else if ((yr < 1) || (yr > 9999))
    {
	cout << "N" << endl;
    }
    
// if any of these months are entered, the date entered must be between the range of 1 and 31
    else if ( (mon == JAN) || (mon == MAR) || (mon == MAY) || (mon == JUL)  || (mon ==AUG) || (mon == OCT) || (mon == DEC)) 
    {	
	if ( (dte < 1 ) || (dte > 31) )
	{
	    cout << "N" << endl;
	}
	
	else
	{
	    cout << "Y" << endl;
	}
    }	

    else if ( (mon == APR) || (mon == JUN) || (mon == SEPT) || (mon == NOV))
    {
	if ( (dte < 1 ) || (dte > 30 ) )
	{
	    cout << "N" << endl;
	}
	    
	else
	{
	    cout << "Y" << endl;
        }
    }

// if the year is divisible my 400, and if the month entered is February, and the date entered
// is greater than 29, since it will be a leap year if divisible by 400, the terminal outputs 
// N, if it is greater than 29 or less than 1
    if ( ((yr % 400) == 0) )
    {
	if (mon == FEB)
	{
     	        if ((dte > 29) || (dte < 1))
		{
		    cout << "N" << endl;
		}	
	
		else
		{
		    cout << "Y" << endl;
		}
	}
    }

// if above test fails, and it is divisible by 100, it is not a leap year, so there are 28 days
    else if ( (yr % 100 == 0) )
    {	
	if ( mon == FEB)
	{ 
	    if ((dte > 28) || (dte <1))
	    {
		cout << "N" << endl;
	    }     
	 
	    else
       	    {
	       	cout << "Y" << endl;
    	    }
	}

// if not divisible by 400, and is not evenly divisible by 100, but is divisible by 4, then
// it is a leap year, and outputs accordingly
    }
    else if ( (yr % 4) == 0 )
    {
	if (mon == FEB)
	{
	    if ((dte > 29) || (dte <1))
		{
		    cout << "N" << endl;
		}	
	
		else
		{
	 	    cout << "Y" << endl;	
   		}
	}
    }

// if statement to ensure that all other times February is treated according if it is not a leap year
    else if (mon == FEB)
    {
	if ((dte > 28) || (dte < 1))
	{
	    cout << "N" << endl;
	}

	else
	{
	    cout << "Y" << endl;
	}
    }

    return 0;
}

