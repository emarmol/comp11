/*Name: Erika Marmol
Date: 4.22.14
File: FrequencyTable1.cpp-determines how the words should be inserted*/

#include "FrequencyTable1.h"
#include <iostream>

using namespace std;

/*
Purpose: Constructor-intializes the list to empty
Arguments:none
Returns:nothing
Effects:none
Notes:none
*/
FrequencyTable::FrequencyTable()
{
    list = empty();
}

/*
Purpose: Determines if the word is already in the list
Arguments:a string- the word
Returns:true if the word is already in the list, and false otherwise
Effects:none
Notes:none
*/
bool FrequencyTable::in(string word)
{
    WordFreqList temp;
    temp = list;

    while (!isEmpty(temp)) {
      if (word == first(temp).word) {
	return true;
      }
      temp = rest(temp);
    }
        return false;
}

/*
Purpose: Determines if the word needs to be inserted if not already in,
	 updates the frequency of the word whether it's seen the for the 
	 first time or multiple. Alphabetizes as words are inserted.
Arguments:a string-the word
Returns:nothing, is a void function
Effects:will modify the list depending on if the word needs to be inserted
	as the first word in the list, if the word needs to be prepended 
	because it comes earlier in the alphabet, or if it needs to be 
	inserted inbetween two words.
Notes:none
*/
void FrequencyTable::insert(string word)
{   WordFreqList temp = list;
    WordFreq pair;
    pair.word = word;
    pair.freq = frequency(word);
    if (isEmpty(temp)) { 	//checks if inputted word is the first one
	list = prepend(pair, temp);
	temp = list;
	set_freq(temp, 1);
	return;      }
    while (!isEmpty(temp)) {
      if (in(word)) {
	 already_in(temp, pair, word); //helper function if already in list
	 return;	   }
      else if (first(temp).word < pair.word){ // checks if word goes after
	 while (!isEmpty(temp)) {		    
	     if (((rest(temp) == empty()) || 
		(first(rest(temp)).word > pair.word)) 
		 &&(first(temp).word < pair.word))   {
			insertAfter(temp, pair);
			set_freq(rest(temp), frequency(word) + 1);
			return;			     }
	       temp = rest(temp);}	   
	 }
      else if (first(temp).word > pair.word) { // checks if word goes before
	        list = prepend(pair, temp);
                temp = list;
                set_freq(temp, frequency(word) + 1);
		return;			     }
	    temp = rest(temp);
     }
}

/*
Purpose: If word is already in the list, only updates frequency
Arguments:string word, the temp list, word/freq pair (struct), 
	  constant updater t_freq = 1
Returns:nothing, void function
Effects:updates the frequency if already in list
Notes:none
*/
void FrequencyTable::already_in(WordFreqList temp, WordFreq pair, 
			        string word)
{
	   while (!isEmpty(temp)) {
		 if (first(temp).word == pair.word) {
		      set_freq(temp, frequency(word) + 1);
		      return;
	         }
		 temp = rest(temp);
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
    WordFreqList temp;
    temp = list;

    while (!isEmpty(temp)) {
	    if (word == first(temp).word) {
	        freq = first(temp).freq;
		return freq;
	    }
	temp = rest(temp);
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
    WordFreqList temp;
    temp = list;
    int counter = 0;
    while (!isEmpty(temp)) {
	 counter++;
	 temp = rest(temp);
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
Effects:none
Notes:The first word is considered position 0
*/
void FrequencyTable::get(int n, string *p_word, int *p_frequency)
{
    WordFreqList temp;
    temp = list;
    int counter = 0;
    WordFreq tempinfo;
        while (!isEmpty(temp)) { 
  	    if(counter == n) {
		tempinfo.word = first(temp).word;
		tempinfo.freq = first(temp).freq;
	       *p_word = tempinfo.word;
	       *p_frequency = tempinfo.freq;
	       return;
	    }
	    temp = rest(temp);
	    counter ++;
       }
}

/*
Purpose: Destroys (deltes) the table
Arguments:none
Returns:Nothing, is a void function
Effects:deletes the list
Notes:none
*/
void FrequencyTable::destroy()
{
     while (!isEmpty(list)) {
	deleteFirst (list);
	list = rest(list);
    }
}
