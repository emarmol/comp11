/*Name: Erika Marmol
Date: 4.22.14
File: WordFreqList.h- header files that 
      defines the WordFreq struct, and functions used*/

#ifndef __WORDFREQLIST_H__
#define __WORDFREQLIST_H__
#include <string>

using std::string;

struct WordFreqNode;
struct WordFreq {
    int freq;
    string word;
};

typedef WordFreqNode *WordFreqList;

WordFreqList empty();
bool isEmpty(WordFreqList list);
WordFreqList prepend(WordFreq pair,WordFreqList list);
WordFreq first(WordFreqList list);
WordFreqList rest(WordFreqList list);
WordFreqList deleteFirst(WordFreqList list);
void insertAfter(WordFreqList list, WordFreq pair);
void set_freq(WordFreqList list, int num);

#endif
