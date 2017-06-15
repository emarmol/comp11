//
// golf.cpp
//	    version: 2012-09-18 Remove fcn call; keep booleans, consts
//	    purpose: practice using booleans and constants
//	modified by:
//	         on:
//
#include <iostream>
#include <iomanip>
using namespace std;

// days of the week
const int SUN = 0, MON = 1, TUE = 2, WED = 3, THR = 4, FRI = 5, SAT = 6;

// constants for rules
const double	BASE_PRICE            = 9.0;
const int	HIGH_TEMP_CUTOFF      = 80;
const int	LOW_TEMP_CUTOFF       = 65;
const double	PER_DEGREE_PENALTY    = 0.10;
const int	EVENING_START         = 17;
const double	WEEKEND_EVE_SURCHARGE = 1.00;
const double	RAIN_PENALTY          = 2.00;
const int	WIND_GRANULARITY      = 15;
const double	WIND_PENALTY          = 1.50;

// main function here
int main() 
{
	// -- define vars for input and a value used in the tests below
    int	tempF, dayOweek, hour, rainP, windMPH;
	double	price;

	// -- set the precision 
	cout << setiosflags(ios::fixed) << setprecision(2);
	
	// -- Get data from user
	cout << "Temperature (fahrenheit)? ";
	cin  >> tempF;

	cout << "Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)? " ;
	cin  >> dayOweek;
	
	cout << "Hour of day (0..23)? ";
	cin  >> hour;

	cout << "Is it raining (0 = no, 1 = yes)? ";
	cin  >> rainP;

	cout << "Wind speed (MPH)? ";
	cin  >> windMPH;

	// -- compute price based on these values

	price = BASE_PRICE;		// start here then adjust
	if (tempF > HIGH_TEMP_CUTOFF)
	{	    
	    price = price - (tempF-HIGH_TEMP_CUTOFF)*PER_DEGREE_PENALTY;

	}				// ADD YOUR CODE IN THIS PART
	else if (tempF < LOW_TEMP_CUTOFF)
	{
	    price = price - (LOW_TEMP_CUTOFF-tempF) * PER_DEGREE_PENALTY;
	}				// ADD ONE CONDITION AT A TIME
					// THEN TEST, THEN ADD THE NEXT ...

	if ( ((dayOweek > THR) && (dayOweek <= SAT )) || (dayOweek == 0) || (hour >= 16))
	{
	    price = price + WEEKEND_EVE_SURCHARGE;
	}

	if ((dayOweek > 6) || (dayOweek < 0))
	{
	    cout << dayOweek << " is not a valid day of the week" << endl;
	    return 0;
	}

	if (rainP == true)
	{
	    price = price - RAIN_PENALTY;
	}

	if ((rainP > 2) || (rainP <0))
	{
	    cout << rainP << " is not a valid entry for rain " << endl;
	    return 0;
	}	

	// -- report price to user

	cout << "Price: " << price << endl;
	return 0;
}
