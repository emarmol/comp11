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
void digs_strings(char plate[IMG_HGT][IMG_WID], char digs[DIG_NUM][DIG_HGT]
		  [DIG_WID], string string1[], int posx, int posy);
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
	while ( next_image(image) ) {
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
    string string1[] = "";
    for (int i=0; i< IMG_HGT; i++)
    {
	for (int j=0; j< IMG_WID; j++)
	{
	    if (plate[i][j] == POUND)
	    {
		posx = j;
		posy = i;
		while (k < IMG_WID)
		{
	    	   string1[j] = string1[j] + plate[i][j];
		   k++;
		}
	    }
	}
    }
    digs_strings(plate, digs, string1, posx, posy);
}

void digs_strings(char plate[IMG_HGT][IMG_WID], char digs[DIG_NUM][DIG_HGT]
		  [DIG_WID], string string1[], int posx, int posy)
{
    string string2[]= "";
    for (int i=0; i< DIG_HGT; i++)
    {
	for (int j=0; j< DIG_WID; j++)
	{
	    string2[j] = string2[j] + digs[i][j];
	}
    }
}
/*   if (compare_strings(string2, string1))
      {
	cout << digs[DIG_NUM] << "@" << posx << posy << endl;
    }
}

bool compare_strings( string string2[], string string1[])
{
    if( string1[0]==string2[0])
    {
	return true;
    }
}
*/
