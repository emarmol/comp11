/*Name: Erika Marmol
Date: 4/7/14
Purpose: to create an animated fishtank
Discussed ideas with: Emma Coltoff, Jessica Morales. Ambika Jayakumar
 */
#include <iostream>
#include "FishTank.h"
#include "Fish.h"
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

/*Purpose: clears the screen when called
Arguments: none
Returns: nothing, it cout's a command to clear the screen
Effects: clears screen
Notes: none
*/
void clear_screen()
{
        cout << "\033[2J";
}

/*Purpose: sends cursor back to the beginning of the
	   buffer
Arguments: none
Returns: nothing, cout's
Effects: brings back to beginning of buffer
Notes: none
*/
void home_cursor()
{
        cout << "\33[H";
}

/*Purpose: a constructor that is called upon implementation
	   of the FishTank class, which initializes every
	   thing to zero.
Arguments: none
Returns: nothing
Effects: modifies the Tank array to all empty characters
Notes: This one is called only if there are no parameters for
       height and width
*/
FishTank::FishTank()
{
    tank_hgt=0;
    tank_wid=0;
    num_fish=0;
    for (int row=0; row<MAX_HGT; row++)
    {
	for (int col=0; col<MAX_WID; col++)
	{
	  Tank[row][col]=' ';
	}
    }
}

/*Purpose: a constructor that is called upon implementation
	   of the FishTank class, which initializes every
	   thing to zero.
Arguments: none
Returns: nothing
Effects: modifies the Tank array to all empty characters
Notes: Called if parameters are given for the tank's 
       height and width
*/
FishTank::FishTank(int hgt, int wid)
{
    setHeight(hgt);
    setWidth(wid);
    for (int row=0; row<tank_hgt; row++)
    {
	for (int col=0; col<tank_wid; col++)
	{
	    Tank[row][col]=' ';
	}
    }
}

/*Purpose: sets the height of the fish array when called
Arguments: an integer, which is passed in from SimFishy
	   in main.
Returns: nothing, is a void function
Effects: sets the private variable tank_hgt equal to the 
	value that we cin from main in SimFishy
Notes: none
*/
void FishTank::setHeight(int hgt)
{
    tank_hgt = hgt;
}


/*Purpose: sets the width of the fish array when called
Arguments: an integer, which is passed in from SimFishy
	   in main.
Returns: nothing, is a void function
Effects: sets the private variable tank_wid equal to the 
	value that we cin from main in SimFishy
Notes: none
*/
void FishTank::setWidth(int wid)
{
    tank_wid = wid;
}

/*Purpose: gets the height of the tank, checking to make
	   sure it is within the boundaries of the 
	   MAX_HGT.
Arguments: none
Returns: an integer, which is the tank_hgt
Effects: returns 1, exit status if not within bounds
Notes: none
*/
int FishTank::getHeight()
{
    if (tank_hgt <= MAX_HGT)
    {
        return tank_hgt;
    }
    return 1;
}

/*Purpose: gets the width of the tank, checking to make
	   sure it is within the boundaries of the 
	   MAX_WID.
Arguments: none
Returns: an integer, which is the tank_wid
Effects: returns 1, exit status if not within bounds
Notes: none
*/
int FishTank::getWidth()
{
    if (tank_wid <= MAX_WID)
    {
        return tank_wid;
    }
    return 1;
}

/*Purpose: will get the maximum number of fish allowed in
	   tank
Arguments: none
Returns: an integer, which is the max_fish
Effects: none
Notes: none
*/
int FishTank::getMaxFish()
{
    return MAX_FISH;
}

/*Purpose: gets the current number of fish in the tank
Arguments: none
Returns: an integer, which is the num_fish
Effects: none
Notes: none
*/
int FishTank::getNumFish()
{
	return num_fish;
}

/*Purpose: determines if the fish that is read in can be
	   added to the current array of fishes, depending
	   on whether there are MAX_FISH fish in the tank
	   calls draw from here to draw the fish in the tank
	   increments num_fish, adding the fish f to the
	   Fishes array.
Arguments: fish f, which comes from Fish.cpp, is the drawn
	   fish
Returns: a boolean true if the fish is added, and false if
	 it cant be added
Effects: modifies the Fishes array if fish f can be added
Notes: none
*/
bool FishTank::addFish(Fish f)
{
    if (getNumFish() <= getMaxFish())
    {
	Fishes[num_fish] = f;
	num_fish++;
	return true;
    }
    return false;
}

/*Purpose: clears the tank, making everything into blank
	  space characters
Arguments: none
Returns: nothing, is a void function
Effects: modifies the tank array to all blank spaces
Notes: none
*/
void FishTank::clearTank()
{
    for (int i=0; i<tank_hgt; i++)
    {
	for (int j=0; j<tank_wid; j++)
	{
	    Tank[i][j]=' ';
	}
    }
}

/*Purpose: prints out the tank, by using cout for the Tank
	   array
Arguments: none
Returns: nothing, is a void function, but cout's
Effects:none, does not modify array
Notes: none
*/
void FishTank::showTank()
{
    for (int row=0; row<tank_hgt; row++)
    {
	for (int col=0; col<tank_wid; col++)
	{
	    cout << Tank[row][col];
	}
	cout << endl;
    }
}

/*Purpose: is called from Fish.cpp, will update the 
	   picture provided that the new charater passed
	   in is not an expty character. This allows for 
	   "transparency"
Arguments: two integers, for the current row and column, and
	   a character, which is the character at that 
	   position from the fish_map array
Returns: nothing, is a void function
Effects: modifies the tank array, to the new character from
	 the fish array
Notes: none
*/
void FishTank::updateAt(int row, int col, char newChar)
{
    if (newChar != ' ')
    Tank[row][col] = newChar;
}

/*Purpose: simulates the array, in a forever loop, so that
	   it is constantly updating the position, thereby
	   updating the arrays. Calls draw(), move(), 
	   and showTank(). The home_cursor allows it to go
	   back to the beginning of the buffer. Tank must be
	   cleared, so the old images are erased. Will use
	   usleep() if singleStep is false  
Arguments: takes in a bool for singleStep and frames per
	   second
Returns: nothing, is a void function, but cout's
Effects: modifies the arrays for fish_map, and tank
Notes: none
*/
void FishTank::simulate(bool singleStep, int fps)
{
    clear_screen();
    fps = 1000000/fps;
    while (true)
    {
	for (int i =0; i<num_fish; i++)
	{
	   Fishes[i].draw(this);
   	   Fishes[i].move(getHeight(), getWidth());	   
	}
	home_cursor();
	    showTank();
	if (!singleStep)
	{
	    usleep(fps);
	}

	else if (singleStep)
	{
           if(system("read x < /dev/tty") != 0)
           {
	      exit (0);
           }
	}
	    clearTank();
	home_cursor();
    }
}
