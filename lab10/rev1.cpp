// rev1.cpp
// Read in words, reverse, print
//  Shows: dynamically allocated array

#include <iostream>
#include "vector1.h"
using namespace std;

void readin_data(Vector *data, int length);
void rev_list   (Vector *data);
void print_list (Vector *data);

int main() 
{
        int num;

        cout << "How many numbers? ";
        cin  >> num;

        Vector data(num);

        readin_data(&data, num);
        rev_list(&data);
        print_list(&data);

        return 0;
}


// -- read in a list of integers ---
//   args: data
//   rets: nothing
//   errs: quits on too many words

void readin_data(Vector *data, int length)
{
    int input;
    for (int i=0; i<length; i++)
    {
	cin >> input;
//	(*data).add(input); same as bottom syntax
	data->add(input);
}


// -- reverse an array ---
//  args: Vector of int
//  rets: nothing
//  mods: reverses array

void rev_list(Vector *data)
{
        // STUB
}

// -- print out a list of integers
//  args: Vector of int
//  rets: nothing
//  mods: modifies cout, not data

void print_list(Vector *data)
{
        for (int i = 0; i < data->getSize(); i++) {
                cout << data->get(i) << endl;
        }
}
