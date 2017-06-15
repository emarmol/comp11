/*Name: Erika Marmol
Date: 4/7/14
Purpose: to create an animated fishtank
Discussed ideas with: Emma Coltoff, Jessica Morales. Ambika Jayakumar
 */
#include <iostream>
#include "FishTank.h"
#include "Fish.h"
#include <unistd.h>
using namespace std;

/*Purpose: client info-will read in information for the FishTank
	   
Arguments: none
Returns: zero to indicate end of function
Effects:creates multiple fish f, until end of file, and a fishtank
Notes: none
*/
int main()
{
    string tank = "";
    string fish ="";
    int tank_hgt=0;
    int tank_wid=0;
    bool step=false;
    static const int FRAMES = 15;

    cin >> tank >> tank_hgt >> tank_wid;
    FishTank Tank(tank_hgt, tank_wid);
    		  while (!cin.eof())
    		  {
		       Fish f;
		       if(f.readFish())
		       {
	    		     Tank.addFish(f);
		       }
   		  }
		  Tank.simulate(step,FRAMES);
    return 0;
}
