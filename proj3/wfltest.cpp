#include "WordFreqList.h"
#include <iostream>

using namespace std;

void commandLoop();
string getCommand();
void promptForCommand();
WordFreqList prependCmd(WordFreqList list);

int main()
{
    commandLoop();
    return 0;
}

void commandLoop()
{
    string cmd;
    WordFreqList words = empty();

    while ((cmd = getCommand()) != "quit") {
	if (cmd=="print") {
	    print(words);
	    cout << endl;
	}
	else if ( cmd=="prepend") {
	    words = prependCmd(words);
	}
	else if ( cmd=="delete") {
	    words = deleteFirst(words);
	}
	else if (cmd == "isEmpty") {
	    if (isEmpty(words))
  	       cout << "yes" << endl;
	    else 
	       cout << "no" << endl;
	}
    }
}

string getCommand()
{
    string cmd;
    promptForCommand();
    cin >> cmd;
    return cmd;
}

void promptForCommand()
{
    cout << " prepend to list" << endl
	 << " delete first element " << endl
	 << " isEmpty" << endl
	 << " print the list " << endl
	 << " printArtistically" << endl
	 << " quit" << endl
	 << ": ";
}

WordFreqList prependCmd (WordFreqList list)
{
    WordFreq pair; //or WordFreqList?
    cout << "Enter a word to prepend: ";
    cin >> pair.freq;
    cin >> pair.word;
    return prepend(pair, list);
}
