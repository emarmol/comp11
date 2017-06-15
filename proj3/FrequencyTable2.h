/*Name: Erika Marmol
Date: 4.22.14
File: FrequencyTable2.h- header files that 
      creates the FrequencyTable class*/

#include "WordFreqList.h"
#include <string>
using std::string;

#ifndef __FREQUENCY_TABLE__
#define __FREQUENCY_TABLE__
class FrequencyTable
{
public:

    FrequencyTable();
    bool in(string word);
    void insert(string word);
    int frequency(string word);
    int size();
    void get(int n, string *p_word, int *p_frequency);
    void destroy();

private:

     static const int SIZE = 25;
     WordFreqList alphabet_list[SIZE];
    
};

#endif
