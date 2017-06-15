/*Name: Erika Marmol
Date: 4.22.14
File: wordfreq.cpp -client code*/

#include <iostream>
#include <string>
#include "FrequencyTable.h"
using namespace std;
using std::string;

string lowercase(string word);

/*
Purpose: Will read in the information for the words until
	 there are no more to read. Checks to see if the word
	 begins with a letter; sends to be converted to lowercase.
	 Will call insert to insert the word into the table.
	 Prints out the table using the get() function.
Arguments:none
Returns:nothing
Effects:reads in information, chainging list, prints out table
Notes:none
*/
int main()
{
    string *p_word; 
    int *freq;
    int tempfreq=0;

    FrequencyTable table;
    string word="";

    while (cin >> word) {
	if (isalpha(word[0])) {
	    word = lowercase(word);
	    table.insert(word);
	}	       
    } 

    p_word = &word;
    freq = &tempfreq;
    for (int location = 0; location < table.size(); location++) {
      table.get(location, p_word, freq);
      cout << *freq << " " << *p_word << endl;
    }
    table.destroy();
    return 0;
}

/*
Purpose: will convert given words to lowercase
Arguments: a string being the word to be converted
Returns: The lowercase word
Effects:none
Notes:none
*/
string lowercase(string word)
{
    int len = word.length();

    for (int i = 0; i<len; i++) {
	word[i] = tolower(word[i]);
    }

    return word;
}
