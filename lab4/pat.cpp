//
//  pat.cpp  -- draw a checkerboard pattern
//  version1: draws 8 rows of 8 chars alternating X and -
//  Goal: allow user to enter two strings and 
//		the number of pairs per line
//		the number lines per set
//		the number sets per image
//
//  tools: loops and functions(with arguments)
//

#include <iostream>

using namespace std;

void twolines(string s1, string s2, int reps);

int main()
{

    int how_many, times;
    int counter = 0;
    string word1, word2;

    cout << "Type two strings:" << endl;
    cin >> word1 >> word2;

    cout << "How many pairs per row?" << endl;
    cin >> times;

    cout << "How many pairs of rows?" << endl;
    cin >> how_many;

    while (counter < how_many)
    {
	twolines(word1, word2, times);
	counter++;
    }
        
    return 0;
}

void twolines(string s1, string s2, int reps)
{
    int counter = 0;
    int counter2 = 0;
    int lines = reps;
	
    while (counter < lines)
    {		
    	cout << s1 << s2;
	counter++;
    }

    cout << endl;

    while (counter2 < lines)
    {
	cout << s2 << s1;
	counter2++;
    }
    cout << endl;
}
