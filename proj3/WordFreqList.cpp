/*Name: Erika Marmol
Date: 4.22.14
File: WordFreqList.cpp- implementation of the list
      that modify the list*/

#include <iostream>
#include <string>
#include "WordFreqList.h"
using namespace std;
using std::string;

//Defines the struct WordFreqNode which holds another struct
// of type WordFreq, and a pointer to itself.
struct WordFreqNode {
    WordFreq info;
    WordFreqNode *next;
};

/*
Purpose: Defines the empty list
Arguments:none
Returns:NULL; the empty list
Effects:none
Notes:none
*/
WordFreqList empty()
{
    return NULL;
}

/*
Purpose: Determines if the list is empty
Arguments: pointer to the list
Returns: true if the list is empty, false if it is not
Effects:none
Notes:none
*/
bool isEmpty(WordFreqList list)
{
    return list == empty();
}

/*
Purpose: adds a new word/freq pair to the list
Arguments:word/freq pair (struct), and a pointer to the list
Returns: a pointer to the location the word/freq have been added
Effects: none
Notes:none
*/
WordFreqList prepend(WordFreq pair, WordFreqList list)
{
    WordFreqNode *p_node = new WordFreqNode;
    p_node->info = pair;
    p_node->next = list;
    return p_node;
}

/*
Purpose: Will determine what the first node in the list is
Arguments:pointer to the list
Returns:the word/freq pair (struct) in the first node
Effects:none
Notes:if list is not empty
*/
WordFreq first(WordFreqList list)
{
    return list->info;
}

/*
Purpose: Gives back the list after the first node
Arguments:pointer to the list
Returns: a pointer to the rest of the list 
	 (everything after the first node)
Effects:none
Notes:if the list is not empty
*/
WordFreqList rest(WordFreqList list)
{
     return list->next;
}

WordFreqList deleteFirst (WordFreqList list)
{
    WordFreqList Rest = rest(list);
    list->next = NULL;
    delete list;
    return Rest;
}

/*
Purpose: Will insert a word inbetween two others, uses prepend
Arguments:pointer to the list, and a word/freq pair (struct)
Returns:nothing, is a void function
Effects:none
Notes: if list is not empty
*/
void insertAfter(WordFreqList list, WordFreq pair)
{
    WordFreqNode *node= new WordFreqNode;
    node = prepend(pair, rest(list));
    list->next=node;
}

/*
Purpose: Extracts the frequency stored in the struct's
	 frequency function
Arguments:pointer to the list, and an integer
Returns:Nothing, is a void function
Effects:none
Notes:none
*/
void set_freq(WordFreqList list, int num)
{ 
    list->info.freq = num;
}
