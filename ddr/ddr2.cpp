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
//void digs_strings(char plate[IMG_HGT][IMG_WID], char digs[DIG_NUM][DIG_HGT]
//		  [DIG_WID], string string1[], int posx, int posy);
//bool compare_strings( string string2[], string string1[]);


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
	cout << "opening";
	while ( next_image(image) ) {
	    cout << "true";
		analyze(image, digits);
       
	}
	return 0;
}

//
// Your code goes down here
// add comments here
//
void analyze(char plate[IMG_HGT][IMG_WID],char digs[DIG_NUM][DIG_HGT][DIG_WID])
{
    char POUND = '#';
    int posx = 0;
    int posy = 0;
    int k = 0;
    string row="#####";
    string col="#######";
    string string1= "";
    string string2="";
    string string3="";
    string string4="";
    string string5="";
    string string6="";
    string string7="";
    for (int i=0; i< IMG_HGT; i++)
    {
	for (int j=0; j< IMG_WID; j++)
	{
	    cout << j;
	    if (plate[i][j] == POUND)
	    {
		posx = j;
		posy = i;
//call new function that does comparisons
	    }
		while (k < 5)
		{
	        	if ( plate [0][j] == POUND) 
			{
			    string1= string1 + plate[0][j];
			}
			if (plate [i][0] ==POUND)
			{
			    string2 = plate[i][0];
			}
			if (plate[7][j] == POUND)
			{
			    string3= plate[7][j];
			}
			if (plate[i][5] == POUND)
			{
				string4=plate[i][5];
			}
			if (plate[3][j] == POUND)
			{
			    string5=plate[3][j];
			}
			if (plate[i][7] == POUND)
			{
			    string6=plate[i][7];
			}
			if (plate[7][j] == POUND)
			{
			    string7=plate[7][j];
			}
		       

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
					    cout << "8 @" << posx << posy;
					}
					else
					{
					    cout << "0 @" << posx << posy;
					}
				    }
				    else
				    {
					cout << "6 @" << posx << posy;
				    }
				}
				else if ( string6 == row)
				{
				    if (string7== col)
				    {
					cout << "3 @ " << posx << posy;
				    }
				    else if (string5==row)
				    {
					cout << "9 @ " << posx << posy;
				    }
				    else 
				    {
					cout << "7 @ " << posx << posy;
				    }
				}
				else if (string5==row)
				{
				    cout << "2 @ " << posx << posy;
				}
			    }
			
			    else if (string2 == col)
			    {
				cout << "1 @ " << posx << posy;
			    }
			    else
			    {
				cout << "? @ " << posx << posy;
			    }
			}			
		}	    
	}
    }
	//   digs_strings(plate, digs, string1, posx, posy);
}

//void digs_strings(char plate[IMG_HGT][IMG_WID], char digs[DIG_NUM][DIG_HGT]
//		  [DIG_WID], string string1[], int posx, int posy)
//{

