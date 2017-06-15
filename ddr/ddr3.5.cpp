#include <iostream>
#include <cstdlib>
#include "ddrlib.h"
using namespace std;

// ddr.cpp: digital digit recognizer
//
//  purpose: read in plates of bitmaps and find the digits in those images
//     uses: a file of digit bitmaps
//    input: a sequence of images from cin
//   output: for each image, a list of the digits and their locations
//   format: 2 @ 2,1 3 @ 2,12 6 @ 3,20 ... -1
//  details: each digit is listed as the digit, a space, an @ sign,
//           a space, then the row, col with a comma (and no space)
//           between them.
//           The end of the list has a -1 sentinel value
//   errors: any character it cannot recognize is reported as
//           ? @ row,col   where row,col are the actual coordinates of
//           the upper left pixel in the character
//
//  Code by: Erika Marmol
//     Date: the date
//

void analyze(char [IMG_HGT][IMG_WID], char [DIG_NUM][DIG_HGT][DIG_WID]);
int num_rec(char plate[IMG_HGT][IMG_WID], int posx, int posy);
int  which_string(char plate[IMG_HGT][IMG_WID], int posx, int posy);
int comparisons( string string1, string string2, string string3,
		 string string4, string string5, string string6,
		 string string7, int posx, int posy);

const int SENTINEL = -1;
const char POUND = '#';

int main(int ac, char *av[])
{
	char	digits[DIG_NUM][DIG_HGT][DIG_WID];
	char	image[IMG_HGT][IMG_WID];

	if ( ac == 1 ) {
		cerr << "usage: " << av[0] << " digit_bitmap_file\n";
		exit(1);
	}
	if ( read_patts( string(av[1]), digits, DIG_NUM ) != DIG_NUM ) {
		cerr << av[0] << ": error - too few digit bitmaps\n";
		exit(1);
	}
	
	open_image("");
	while ( next_image(image) ) {
		analyze(image, digits);
       
	}
	return 0;
}

void analyze(char plate[IMG_HGT][IMG_WID],char digs[DIG_NUM][DIG_HGT][DIG_WID])
{
    int posx=0;
    int posy=0;
    int counter=0;
    bool first=false;
    int number=0;

    for (int i =0; (i<IMG_HGT && first==false); i++)
    {
	for (int j=0; j< IMG_WID; j++)
	{
	     if (plate[i][j] == POUND)
	     {
		 counter = 1;
		 first = true;
	     }
	     if (counter == 1)
	     {
		  posx = j;
	          posy=i;
		  number = num_rec(plate, posx, posy);
	  
		  cout << number << " @ " << posx << "," << posy
		       << endl;
		  counter = 0;
		  j=j+4;
	     }	 
	}
    }        
}

int num_rec(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    return which_string(plate, posx, posy);
}

int which_string(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    string string1="";
    string string2="";
    string string3="";
    string string4="";
    string string5="";
    string string6="";
    string string7="";

    for (int i=posy; i<DIG_HGT; i++)
    {
	for (int j=posx; j>DIG_WID; j++)
	{
	    if (plate[0][j] == POUND)
	    {
		string1=string1 + plate[0][j];
	    }
	    if (plate[i][0] == POUND)
	    {
		string2=string2 + plate[i][0];
	    }
	    if (plate[7][j] == POUND)
	    {
   	        string3= string3 + plate[7][j];
	    }
	    if (plate[i][4] == POUND)
	    {
	      	string4= string4 + plate[i][5];
	    }
	    if (plate[3][j] == POUND)
	    {
       	        string5= string5 + plate[3][j];
	    }
	    if (plate[i][] == POUND) 
	    {
	        string6= string6 + plate[i][7];
	    }
	    if (plate[7][j] == POUND)
	    {
	        string7= string7 + plate[7][j];
	    }
	}
    }
    return comparisons (string1, string2, string3, string4, string5, string6,
		 string7, posx, posy);


}

int comparisons( string string1, string string2, string string3,
		 string string4, string string5, string string6,
		 string string7, int posx, int posy)
{

   string row="#####";
    string col="#######";

    for (int i=posy; i<DIG_HGT; i++)
    {
	for (int j=posx; j<DIG_WID; j++)
	{
		if ( string1 == row)
		{
			    if (string2==col)
			    {
				if (string3==row)
				{
				    if (string4 == col)
				    {
					if (string5 == row)
					{
					    return 8;
					}
					else
					{
					    return 0;
					}
				    }
				    else
				    {
					return 6;
				    }
				}
				else if ( string4 == row)
				{
				    if (string7== col)
				    {
					return 3;
				    }
				    else if (string5==row)
				    {
					return 9;
				    }
				    else 
				    {
					return 7;
				    }
				}
				else if (string5==row)
				{
				    return 2;
				}
			    }
			
			    else if (string2 == col)
			    {
				return 1;
			    }
			    else
			    {
				return 123123;
			    }
			}			
		}	
    }
}



