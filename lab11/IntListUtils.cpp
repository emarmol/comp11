/***********************************************************************/
/*                          IntList Utilities                          */
/***********************************************************************/

#include <iostream>

using std::cout;

#include "IntList.h"


/*
 * Can use a while or for loop. 
 */
void print(IntList list)
{
    cout << "[";
    while (!isEmpty(list)) {
	cout << first(list);
	if (!isEmpty(rest(list))){
	    cout << ", ";
	}
	list = rest(list);
    }
    cout << "]";
}

// 	4 ~> 3 ~> ()
void printArtistically(IntList list)
{
    while (!isEmpty(list)) {
	cout << first(list);
	if (!isEmpty(Rest(list))) {
	    cout << "~> ";
	}
	else {
	    cout << "()";
	}
	list =rest(list);
    }
}

int sumList(IntList list)
{
    int sum=0;
    while (!isEmpty(list)) {
	sum = sum + first(list);
	list = rest(list);
    }
	return sum;
}

int length(IntList list)
{
    int length = 0;
    while (!isEmpty(list)) {
	length++;
	list = rest(list);
    }
    return length;
}

IntList copy(IntList list)
{
    IntList newlist=empty();
    IntList list2;
    while (!isEmpty(list)) {
	newlist = prepend(list);
	list = rest(list);
    }
    while (!isEmpty(newlist)) {
	list2 = first(newlist);
	newlist = rest(newlist);
    }
	return list2;
}

IntList mapIncrement(IntList list)
{
    IntList newlist=empty();
    IntList list2;
    while (!isEmpty(list)) {
	newlist = prepend(list);
	list = rest(list);
    }
    while (!isEmpty(newlist)) {
	first(newlist) = first(newlist) + 1;
	list2 = first(newlist);
	newlist = rest(newlist);
    }
	return list2;
}

IntList mapIncrementBy(IntList list, int increment)
{
    IntList newlist=empty();
    IntList list2;
    while (!isEmpty(list)) {
	newlist = prepend(list);
	list = rest(list);
    }
    while (!isEmpty(newlist)) {
	first(newlist) = first(newlist) + increment;
	list2 = first(newlist);
	newlist = rest(newlist);
    }
	return list2;
}

IntList sum(IntList list1, IntList list2)
{
    IntList newlist=empty();
    IntList list2;
    while (!isEmpty(list)) {
	newlist = prepend(list);
	list = rest(list);
    }
    while (!isEmpty(newlist)) {
	first(newlist) = first(list) + first(list2);
	list2 = first(newlist);
	newlist = rest(newlist);
    }
	return list2;
}

IntList filterPositive(IntList list)
{
	// STUB
	return empty();
}

IntList range(int lo, int hi)
{
	// STUB
	return empty();
}

void deleteList(IntList *p_list)
{
	// STUB
}
