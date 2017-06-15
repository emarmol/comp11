// A dynamic array that resizes as new elements are added


// including to get NULL
#include <iostream>

#include "vector2.h"

//  Initialize a vector with capacity of 10 elements
//  args: capacity of the Vector
Vector::Vector()
{
        capacity   = 10;
        data       = new int[capacity];
        n_elements = 0;
}

//  Destroys a vector
Vector::~Vector()
{
        delete [] data;
        data     = NULL;
        capacity = n_elements = 0;
}

//  Returns size of the Vector
//  rets: number of elements in the Vector
int Vector::getSize()
{
        return n_elements;
}

//  Returns capacity of the Vector
//  rets: maximum number of elements that can be stored in the Vector
int Vector::getCapacity()
{
        return capacity;
}

//  Returns element at the given index
//  args: index of the element
//  rets: element at the given index
int Vector::get(int index)
{
        // STUB
}

//  Adds the given element to end of the array.
//  args: element to be added
void Vector::add(int element)
{
    if (n_elements >= capacity)
    {
	int *temp[capacity*2]; //must be pointer, or else it would die
			       //when out of function
	for (int i=0; i<capacity; i++)
	{
	    temp[i]=data[i];
	    delete[] data;
	    data=&temp;
	    data=temp;
	    capacity=capacity*2;
	}
	data[n_elements]=element;
	n_elements++;
	return true;
    }
}

//  Places the given element at the given index
//  args: element and index
void Vector::add(int element, int index)
{
        // STUB
}

//  Makes sure the vector can hold the given number of elements.
//  If it's big enough do nothing.  Otherwise, increase the size to
//  the maximum of the given newCapacity and (2 * current capacity) + 2
//   args: new capacity of the Vector
void Vector::ensureCapacity(int newCapacity)
{
        // STUB
}
