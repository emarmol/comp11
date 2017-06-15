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
//  Collaborated with Emma Coltoff for series4 situation
//     Date: 3/9/14
//

// declaration of functions
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
void clear_num(char plate[IMG_HGT][IMG_WID], int posx, int posy);

// defining constants
const int SENTINEL = -1;
const char POUND = '#';
const char PERIOD = '.';

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

// Purpose: identifies first pound sign. Stores	the location of the pound 
//	    sign, and calls other functions to identify the number. 
//	    Calls clear_num, to modify the array; the number found
//	   sets positions in for loop back to zero to look for the next number.
//Arguments: the 2D array plate[][] is passed; digs[][][] is an argument
//	     however, it is not used--voided in first line of analyze().
//Returns:  Nothing, it is a void function
//Effect:   modifies the array because it replaces the pound signs with
//	    periods as soon as the number is identified and printed.
//Notes:    Is a void function
void analyze(char plate[IMG_HGT][IMG_WID],char digs[DIG_NUM][DIG_HGT][DIG_WID])
{
    (void) digs; // not using
    int posx=0;
    int posy=0;
    int counter=0;
    string number= "";
    do {
	for (int j =0; (j<IMG_WID); j++) {
	for (int i=0; i < IMG_HGT; i++)	{
	     if (plate[i][j] == POUND)  {
		 counter = 1;
	     }
	     if (counter == 1)  {
		  posx = j;
	          posy=i;
		  number = num_rec(plate, posx, posy);	  
		  cout << number << " @ " << posy << "," << posx << " ";
		  counter = 0;

		  clear_num(plate, posx, posy);
		  
		  i=0;
		  j=0;
	     }
	}
    } 
    cout << SENTINEL << endl;
    } while (plate[IMG_HGT][IMG_WID] != SENTINEL);       
}

//Purpose: first function called from analyze(), used to compare on the plate 
//	   array to see if they contain pound symbols. If conditions are met 
//	   for the row the first pound sign if found, and there is a pound 
//	   symbol four spaces away from the x position, and there is no pound 
//	   symbol at posy,posx+1, the number must be a four. If not, the next 
//	   function next_num() is called.
//Arguments: the 2D array plate[][], and the position of the first pound
//	    symbol--posx, posy.
//Returns: a string, which will be the number printed
//Effects: Does not modify the array
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

//Purpose: function is called from num_rec() if the conditions for a four
// 	   were not met. Has the  condition, if there are no pound symbols
//	   at the position [0][1], or [posy][posx+1], then the number must
//	   be a 1. If not, it calls the next function--new_num()
//Arguments: the 2D array plate[][] and the position of the first pound 
//	     symbol--posx, posy
// Returns: a string, which is the number 1, or a string containting a
// 	    different number if the else condition is satified from another
//	    function
//Effects:  Does not modify the array
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

//Purpose: called from next_num if the condition for the 
//	   number one was not true. Will check to see if pound symbols
//	   are found in the array in the specific locations that would
//	   only result in the possibility of the number 7. Else, it calls
//	   the next function to see if it's a different number.
//Arguments: the 2D array, and the position of the first pound symbol
//	     -- posx, and posy
//Returns:  a string, that is the number 7, or a string containting a
// 	    different number if the else condition is satified from another
//	    function
//Effects: does not modify the array
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

//Purpose: is called from new_num() if the condition for the 
//	   number seven was not true. Will check to see if pound symbols
//	   are found in the array in the specific locations that would
//	   only result in the possibility of the number 0. Else, it calls
//	   the next function to see if it's a different number.
//Arguments: the 2D array, and the position of the first pound symbol
//	     -- posx, and posy
//Returns:  a string, that is the number 0, or a string containting a
// 	    different number if the else condition is satified from another
//	    function
//Effects: does not modify the array
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

//Purpose: is called from num0() if the condition for the number 0 was not 
//	   true. Will check to see if pound symbols are found in the array in 
//	   the specific locations that would only result in the possibility of
//	   the number 8. Else calls the next function; see if different number.
//Arguments: the 2D array, and the position of the first pound symbol
//	     -- posx, and posy
//Returns:  a string, that is the number 8, or a string containting a
// 	    different number if the else condition is satified from another
//	    function
//Effects: does not modify the array
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

//Purpose: this function is called from num8() if the condition for the 
//	   number 8 was not true. Will check to see if pound symbols
//	   are found in the array in the specific locations that would
//	   only result in the possibility of the number 3. Else, it calls
//	   the next function to see if it's a different number.
//Arguments: the 2D array, and the position of the first pound symbol
//	     -- posx, and posy
//Returns:  a string, that is the number 3, or a string containting a
// 	    different number if the else condition is satified from another
//	    function
//Effects: does not modify the array
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

//Purpose: this function is called from num3() if the condition for the 
//	   number 3 was not true. Will check to see if pound symbols
//	   are found in the array in the specific locations that would
//	   only result in the possibility of the number 6. Else, it calls
//	   the next function to see if it's a different number.
//Arguments: the 2D array, and the position of the first pound symbol
//	     -- posx, and posy
//Returns:  a string, that is the number 6, or a string containting a
// 	    different number if the else condition is satified from another
//	    function
//Effects: does not modify the array
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

//Purpose: this function is called from num6() if the condition for the 
//	   number 6 was not true. Will check to see if pound symbols
//	   are found in the array in the specific locations that would
//	   only result in the possibility of the number 5. Else, it calls
//	   the next function to see if it's a different number.
//Arguments: the 2D array, and the position of the first pound symbol
//	     -- posx, and posy
//Returns:  a string, that is the number 5, or a string containting a
// 	    different number if the else condition is satified from another
//	    function
//Effects: does not modify the array
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

//Purpose: this function is called from num5() if the condition for the 
//	   number 5 was not true. Will check to see if pound symbols
//	   are found in the array in the specific locations that would
//	   only result in the possibility of the number 2. Else, the only
//	   other possible number would be a 9
//Arguments: the 2D array, and the position of the first pound symbol
//	     -- posx, and posy
//Returns:  a string, that is the number 2, or 9
//Effects: does not modify the array
string num2(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    if (plate[posy+4][posx]==POUND) {
	return "2";
    }
    else {
	return "9";
    }
}

//Purpose: this function is called in analyze() and loops through the 
//	   height and width of the digit, starting at the position of the 
//	   first pound symbol. If it finds a pound symbol, it will be 
//	   replaced by a period effectively 'deleting' the number so the
//	   next one may be found.
//Arguments: the 2D array--plate[][], and the positions of the first pound
//	     symbol--posx,posy
//Returns: Nothing, it is a void function
//Effects: modifies the array--it is taking away the pound symbols as they
//	   are analyzed.
//Notes: This is a void function
void clear_num(char plate[IMG_HGT][IMG_WID], int posx, int posy)
{
    for (int i = posx; i<DIG_WID+posx; i++) {
	for (int j=posy; j<DIG_HGT+posy; j++) {
	    if (plate[j][i] == POUND) {
		plate[j][i] = PERIOD;
	    }
	}
    }
}
