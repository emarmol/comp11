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
string next_num( char plate[IMG_HGT][IMG_WID], int posx, int posy);
string new_num( char plate[IMG_HGT][IMG_WID], int posx, int posy);
string num0( char plate[IMG_HGT][IMG_WID], int posx, int posy);
string num8(char plate[IMG_HGT][IMG_WID], int posx, int posy);
string num3(char plate[IMG_HGT][IMG_WID], int posx, int posy);
string num6(char plate[IMG_HGT][IMG_WID], int posx, int posy);
string num5(char plate[IMG_HGT][IMG_WID], int posx, int posy);
string num2(char plate[IMG_HGT][IMG_WID], int posx, int posy);

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
    (void) digs; // not using
    int posx=0;
    int posy=0;
    int counter=0;
    //   bool first=false;
    string number= "";
    do {
	for (int j =0; (j<IMG_WID); j++) {
	for (int i=0; i < IMG_HGT; i++)	{
	     if (plate[i][j] == POUND)  {
		 counter = 1;
		 //	 first = true;
	     }
	     if (counter == 1)  {
		  posx = j;
	          posy=i;
		  number = num_rec(plate, posx, posy);	  
		  cout << number << " @ " << posy << "," << posx << " ";
		  counter = 0;	
		  i=0;
	          j=j+5;	  
	     }
	}
    } 
    cout << SENTINEL << endl;
    } while (plate[IMG_HGT][IMG_WID] != SENTINEL);       
}

string num_rec(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
	    if (plate[posy][posx+4]==POUND 
		&& plate[posy][posx+1]!= POUND) {
		return "4";
	    }
	    else {
		return next_num( plate, posx, posy);
	    }
 return "?";
}

string next_num( char plate[IMG_HGT][IMG_WID], int posx, int posy)
{

    if  (plate[posy][posx+1]!=POUND) {
	return "1";
    }
    else {
	return new_num(plate, posx, posy);
    }
 return "?";
}

string new_num( char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    if (plate[posy+6][posx+3]!=POUND && plate[posy+1][posx] != POUND
	&& plate[posy+6][posx]!=POUND) {
	    return "7";
	}
    else {
	    return num0(plate, posx, posy);
    }
    return "?";
}

string num0( char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    if ( (plate[posy+3][posx+2]!=POUND)) {
	return "0";
    }
    else {
	return num8(plate, posx, posy);
    }
    return "?";
}

string num8(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    if (plate[posy+1][posx] ==POUND && plate[posy+4][posx]==POUND &&
	plate[posy+1][posx+4]==POUND) {
	return "8";
    }
    else {
	return num3(plate, posx, posy);
    }
    return "?";
}

string num3(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    if (plate[posy][posx+4]==POUND &&
	plate[posy+6][posx]==POUND && plate[posy+6][posx+4]==POUND &&
	plate[posy+1][posx+4]==POUND && plate[posy+4][posx+4]==POUND
	&& plate[posy+1][posx]!=POUND){
	return "3";
    }
    else{
	return num6(plate, posx, posy);
    }

    return "?"; 
}

string num6(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{

    if (plate[posy+1][posx]==POUND && plate[posy+4][posx+4]==POUND &&
        plate[posy+3][posx+2]==POUND && plate[posy+4][posx]==POUND){
	return "6";
    }
    else {
	return num5(plate, posx, posy);
    }
    return "?";
}

string num5(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    if (plate[posy+1][posx+4] != POUND) {
	return "5";
    }
    else {
	return num2(plate, posx, posy);
    }
    return "?";
}

string num2(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    if (plate[posy+4][posx]==POUND) {
	return "2";
    }
    else {
	return "9";
    }
}
