/*Name: Erika Marmol
Date: 4/7/14
Purpose: to create an animated fishtank
Discussed ideas with: Emma Coltoff, Jessica Morales. Ambika Jayakumar
 */
#include <iostream>
#include <string>
#include "Fish.h"
#include "FishTank.h"
using namespace std;

// constructor:initializes the Fish class to zeros for 
// int and float values and to empty strings.
Fish::Fish()
{
    fish_name = "";
    fish_vspeed=0;
    fish_hspeed=0;
    fish_posx=0;
    fish_posy=0;
    fish_hgt=0;
    fish_wid=0;
}

/*Purpose: the purpose of readFish is to read the
	   information inputted about the fish, reading
	   in the fishes height, width, (x,y) position,
	   vertical and horizontal speeds, and the fishes
	   name, reads lines of fish using getline() 
Arguments: none
Returns: a boolean true of false as to whether it can read
	 the fish inputted, returns false if it can't
	 read the inputted ascii fish
Effects: modifies the fish_map array, and the private
	 variables for the fishes specifications
Notes: none
*/
bool Fish::readFish()
{
    string line="";
    string fish="";
    cin >> fish >> fish_hgt >> fish_wid
	>> fish_posy >> fish_posx 
	>> fish_vspeed >> fish_hspeed
	>> fish_name;
    getline(cin, line);
    if (fish == "fish" && fish_hgt <=MAX_HGT &&
		fish_wid<= MAX_WID)
    {
	for (int row=0; row<fish_hgt; row++)
	{ 
	     getline(cin,line);
	     for (int col=0; col<fish_wid; col++)
	     {
		  fish_map[row][col]=line[col];
	     }
	}
	setPos(fish_posy, fish_posx);
	setHSpeed(fish_hspeed);
	setVSpeed(fish_vspeed);
	setName(fish_name);
	return true;
    }
    else if (cin.eof())
    {
       return false;
    }
    return false;
}

/*Purpose: gets the name from readFish() and sets the
	   and returns it
Arguments: none
Returns: a string, which is the fishes name
Effects: none
Notes: none
*/
string Fish::getName()
{
    return fish_name;
}

/*Purpose: sets the fishes name from readFish()
	   equal to the private variable in Fish.h which is
	   fish-name.
Arguments: a string, from readFish is passed in
Returns: nothing, it is a void function
Effects: changes the private variable fish_name
Notes: none
*/
void Fish::setName(string name)
{
       fish_name=name;
}

/*Purpose: sets the horizontal speed of the fish to the 
	   inputted value from readFish()
Arguments: a float, from readFish(), which was inputted
Returns: nothing, it is a void function
Effects: modifies the private variable fish_hspeed
Notes: none
*/
void Fish::setHSpeed(float new_speed)
{
    fish_hspeed=new_speed;
}

/*Purpose: sets the vertical speed of the fish to the 
	   inputted value from readFish()
Arguments: a float, from readFish(), which was inputted
Returns: nothing, it is a void function
Effects: modifies the private variable fish_vspeed
Notes: none
*/
void Fish::setVSpeed(float new_speed)
{
    fish_vspeed=new_speed;
}

/*Purpose: sets the position of the fish to the private
	   variables, called from readFish()
Arguments: two integers, passed in from readFish() for the 
	   row and column
Effects: modifies the private variables fish_posy and fish
	 _posx. Casts them from integers to floats for 
	 internal use
Notes: none
*/
void Fish::setPos(int row, int col)
{
    float row1 = (float) row;
    float col1 = (float) col;
    fish_posy=row1;
    fish_posx=col1;
}

/*Purpose: gets the height for the fish
Arguments: none
Returns: an integer which is the fish's height
Effects: none
Notes: none
*/
int Fish::getHeight()
{
    if (fish_hgt <=MAX_HGT)
        return fish_hgt;
    else 
	return 1;
}

/*Purpose: gets the width for the fish
Arguments: none
Returns: an integer which is the fish's width
Effects: none
Notes: none
*/
int Fish::getWidth()
{
    if (fish_wid <=MAX_WID)
       return fish_wid;
    else 
	return 1;
}

/*Purpose: moves the fish, is called from FishTank
	   and moves the fish according to the fish's 
	   vertical and horizontal speeds
Arguments: tankHeight and tankWidth, which are passed in 
	   from FishTank.cpp
Returns: nothing, it is a void function
Effects: changes the fish_posy and fish_posx
Notes: none
*/
void Fish::move(int tankHeight, int tankWidth)
{
	   fish_posy = fish_posy + fish_vspeed;
	   fish_posx = fish_posx + fish_hspeed;
	  	if (fish_posy > tankHeight)
    	   	{
		     fish_posy = 0;
    	   	}
	   	else if (fish_posy < 0)
	   	{
	       	     fish_posy = tankHeight;
	   	}
	       
    	   	if (fish_posx > tankWidth)
    	   	{
	       		fish_posx = 0;
    	  	 }
	  	 else if (fish_posx < 0)
	   	{
	       		fish_posx = tankWidth;
	   	}
}

/*Purpose: draws the fish, is called everytime from
	  simulate to draw the fish in it's new location
	  also handles the wrap around feature to make sure
	  the fish come back around and appear at the other
	  end of the tank when they read an edge, calls
	  updateAt which is what will place the new fish
	  character in the new location in the fish
Arguments: none
Returns: nothing, it is a void function
Effects: updates the fishes position, changes posx and posy
Notes: none
*/
void Fish::draw(FishTank *tank)
{
    int posy = (int) fish_posy;
    int posx = (int) fish_posx;
    for (int row=0; row<fish_hgt; row++)
    {
	for (int col=0; col<fish_wid; col++)
	{
	    tank->updateAt(posy, posx, fish_map[row][col]);
	    posx++;
	    if (posy > tank->getHeight()-1)
    	   	{
		     posy = 0;
    	   	}
	   	else if (posy < 0)
	   	{
		    posy = tank->getHeight()-1;
	   	}
	       
	    if (posx > tank->getWidth()-1)
    	   	{
	       		posx = 0;
    	  	 }
	  	 else if (posx < 0)
	   	{
		    posx = tank->getWidth()-1;
	   	}	  
	}
	posy++;
	posx= fish_posx;
    }
}

/*Purpose: prints the fish, used for debugging, where
	   to make sure getline() is functioning as
	   expected
Arguments: none
Returns: nothing, it cout's the 2D array of the fish
Effects: none
Notes: none
*/
void Fish::print()
{
    for (int row=0; row<fish_hgt; row++)
    {
	for (int col=0; col<fish_wid; col++)
	{
	    cout << fish_map[row][col];
	}
	cout <<endl;
    }
}
