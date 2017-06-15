/*Name: Erika Marmol
Date: 4.22.14
File: FrequencyTable1.cpp-determines how the words should be inserted*/

#include <iostream>
#include "FrequencyTable2.h"
using namespace std;

/*
Purpose: Constructor-intializes the array to point to NULL
Arguments:none
Returns:nothing
Effects:none
Notes:none
*/
FrequencyTable::FrequencyTable()
{
    for (int i=0; i<SIZE; i++) {
	alphabet_list[i] = empty();
    }
}

/*
Purpose: Determines if the word is already in the list
Arguments: a string- the word
Returns:true if the word is already in the list, and false otherwise
Effects:none
Notes:none
*/
bool FrequencyTable::in(string word)
{
    WordFreqList temp[SIZE];
    for (int i=0; i<SIZE; i++) {
	temp[i] = alphabet_list[i];
    }
    for (int i=0; i<SIZE; i++) {
    	while (!isEmpty(temp[i])) {
      		if (word == first(temp[i]).word) {
	      	return true;
      	        }
      		temp[i] = rest(temp[i]);
   	 }
    }
        return false;
}

/*
Purpose: Determines if the word needs to be inserted if not already in,
	 updates the frequency of the word whether it's seen the for the 
	 first time or multiple. Alphabetizes as words are inserted by 
	 determining the position it should be at.
Arguments:a string-the word
Returns: nothing, is a void function
Effects: will modify the list depending on if the word needs to be inserted
	 as the first word in the list, if the word needs to be prepended 
	 because it comes earlier in the alphabet, or if it needs to be 
	 inserted inbetween two words.
Notes: I apologize for the length of this function
*/
void FrequencyTable::insert(string word)
{   WordFreqList temp[SIZE]; // creates temp array
    for (int i=0; i< SIZE; i++)     
	temp[i] = alphabet_list[i]; 
    WordFreq pair;	    // creates the pair
    pair.word = word;
    pair.freq = frequency(word);
    for (int i=0; i< SIZE; i++) {
        if (isEmpty(temp[i])) {
   	     alphabet_list[i] = prepend(pair, temp[i]);
	     temp[i] = alphabet_list[i];
	     set_freq(temp[i], 1);
	     return;           }
        while (!isEmpty(temp[i])) {
           if (in(word)) {
               while (!isEmpty(temp[i])) {
		  if (first(temp[i]).word == pair.word) {
		      set_freq(temp[i], frequency(word) + 1);
		      return;			       }
		  temp[i] = rest(temp[i]);
	   }
	   return;		      }
        else if (first(temp[i]).word < pair.word){
	    while (!isEmpty(temp[i])) {		    
	       if (((rest(temp[i]) == empty()) ||  //makes sure it is between
		  (first(rest(temp[i])).word > pair.word)) //two words
		  &&(first(temp[i]).word < pair.word)) { // or at end of list
			insertAfter(temp[i], pair);
			set_freq(rest(temp[i]), frequency(word) + 1);
			return;
		}
		temp[i] = rest(temp[i]);
	   }
	}
	else if (first(temp[i]).word > pair.word) { // checks if table word
	    alphabet_list[i] = prepend(pair, temp[i]); //comes before inserted
            temp[i] = alphabet_list[i];
            set_freq(temp[i], frequency(word) + 1);
	    return;				   }
	    temp[i] = rest(temp[i]);
       }
    }
}

/*
Purpose: Determines the frequency of any given word
Arguments:a string-the word
Returns:an integer- the frequency of the word
Effects:none
Notes:none
*/
int FrequencyTable::frequency(string word)
{
    int freq = 0;
    WordFreqList temp[SIZE];
    for (int i=0; i< SIZE; i++) {
	temp[i] = alphabet_list[i];
    }

    for (int i=0; i<SIZE; i++) {
        while (!isEmpty(temp[i])) {
	    if (word == first(temp[i]).word) {
	        freq = first(temp[i]).freq;
		return freq;
	    }
	temp[i] = rest(temp[i]);
        }
    }
    return freq;
}

/*
Purpose: Determines the size (how many words there are in the list)
Arguments:none
Returns:an integer, the size
Effects:none
Notes:none
*/
int FrequencyTable::size()
{
    WordFreqList temp[SIZE];

    for (int i=0; i< SIZE; i++) {
	temp[i] = alphabet_list[i];
    }

    int counter = 0;

    for (int i=0; i <SIZE; i++ ) {
         while (!isEmpty(temp[i])) {
	       counter++;
	       temp[i] = rest(temp[i]);
         }
    }
    return counter;
}

/*
Purpose: Gets the current position of the function given the position of
	 the word, and puts the word and position into the given pointers
Arguments:an integer-the position of the word, a pointer that contains
	  a string for the word, and a pointer that contains an integer for
	  the frequency.
Returns:Nothing, is a void function
Effects:modifies the array
Notes:The first word is considered position 0
*/
void FrequencyTable::get(int n, string *p_word, int *p_frequency)
{
    WordFreqList temp[SIZE];

    for (int i=0; i< SIZE; i++) {
	temp[i] = alphabet_list[i];
    }
    int counter = 0;
    WordFreq tempinfo;

    for (int i=0; i<SIZE; i++) {
        while (!isEmpty(temp[i])) { 
  	    if(counter == n) {
		 tempinfo.word = first(temp[i]).word;
		 tempinfo.freq = first(temp[i]).freq;
	         *p_word = tempinfo.word;
	         *p_frequency = tempinfo.freq;
	         return;
	    }
	    temp[i] = rest(temp[i]);
	    counter ++;
       }
    }
}

/*
Purpose: Destroys (deltes) the table
Arguments:none
Returns:Nothing, is a void function
Effects:deletes the list, modifies the array
Notes:none
*/
void FrequencyTable::destroy()
{
    for(int i=0; i<SIZE; i++) {
         while (!isEmpty(alphabet_list[i])) {
	       deleteFirst (alphabet_list[i]);
	       alphabet_list[i] = rest(alphabet_list[i]);
         }
    }
}

