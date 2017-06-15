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
string num_rec(char plate[IMG_HGT][IMG_WID], int posx, int posy);
string  which_string(char plate[IMG_HGT][IMG_WID], int posx, int posy);
string comparisons( string string1, string string2, string string3,
		 string string4, string string5, string string6,
		 int posx, int posy);

const int SENTINEL = -1;
const char POUND = '#';

int main(int ac, char *av[])
{
    cout << "in main ";
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
	cout << "before loop ";
	while ( next_image(image) ) {
	    cout << "in while loop  ";
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
    string number= "";
    cout<< "in analyze ";
    for (int i =0; (i<IMG_HGT && first==false); i++) {
	for (int j=0; j < IMG_WID; j++)	{
	     if (plate[i][j] == POUND)  {
		 counter = 1;
		 first = true;
	     }
	     if (counter == 1)  {
		  posx = j;
	          posy=i;
		  number = num_rec(plate, posx, posy);
	  
		  cout << number << " @ " << posy << "," << posx
		       << endl;
		  counter = 0;
		  j=j+4;
	     }	 
	}
    }        
}

string num_rec(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    cout << "in num_rec ";
    return which_string(plate, posx, posy);
}

string which_string(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    string string1="";
    string string2="";
    string string3="";
    string string4="";
    string string5="";
    string string6="";
    cout << "in which_string";
    for (int i=posy; i<DIG_HGT + posy; i++) {
	cout << i;
	for (int j=posx; j < DIG_WID + posx; j++) {
	    cout << " (" << j << ")";
	    cout << "in loop2";
	    if (plate[posy][j] == POUND) {
		string1=string1 + plate[posy][j];
	    }
	    cout << string1;
	    if (plate[i][posx] == POUND) {
		string2=string2 + plate[i][posx];
	    }
	    if (plate[posy+6][j] == POUND) {
   	        string3= string3 + plate[posy+6][j];
	    }
	    if (plate[i][posx+4] == POUND) {
	      	string4= string4 + plate[i][posx+4];
	    }
	    if (plate[posy+3][j] == POUND) {
       	        string5= string5 + plate[posy+3][j];
	    }
	    while ((i >= posy) && (i < posy+3)) {
		    if (plate[i][posx] == POUND) {
	   	    	 string6= string6 + plate[i][posx+7];
	    	    }
	    }
	}
    }
    return comparisons (string1, string2, string3, string4, string5, string6,
		        posx, posy);
}

string comparisons( string string1, string string2, string string3,
		 string string4, string string5, string string6,
		 int posx, int posy)
{
   string row="#####";
    string col="#######";
    for (int i=posy; i<DIG_HGT; i++)   {
	for (int j=posx; j<DIG_WID; j++)  {
		if ( string1 == row)  {
			    if (string2==col) {
				if (string3==row)  {
				    if (string4 == col) {
					if (string5 == row) {
					    return "8";
					}
					else {
					    return "0";
					}
				    }
				    else if (string5==row) {
					return "6";
				    }
				}
			    }
			    else if ( string4 == col) {
				if (string5== row)  {
				    if (string3 == row) {
					return "3";
			            }
			            else {
					return "9";
				    }
				}
				else {
					return "7";
				}
			    }
			    else if (string6=="####") {
				    return "2";
			    }
			    else {
				    return "5";
			    }
		}			
		else if (string2 == col) {
		     return "1";
	       }
	       else if (string4==col) {
		     return "4";
	       }	       
	}							
    }
    return "?";
}


