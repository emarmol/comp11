#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
//
// implementation of an Warehouse class
//

#include "warehouse.h"

//
// A constructor that initializes all quantities to zero
//
Warehouse::Warehouse()
{
    for (int i=0; i<NUM_PRODUCTS;i++)
    {
	counts[NUM_PRODUCTS]=0;
    }
    size=0;
    valid_id=false;
}

//
// A constructor that initializes all quantities to the specified amt
//
Warehouse::Warehouse(int init_qty)
{
    for (int i=0; i<NUM_PRODUCTS;i++)
    {
	counts[i]=init_qty;
    }	
}

// Two restock methods, the first adds 'additional'
// units for all products
void Warehouse::restock(int additional)
{
    for (int i=0; i< NUM_PRODUCTS;i++)
    {
	counts[i]=counts[i]+additional;
    }
}
// A restock for a particular product
// this restock method adds an amount to a
// particular product.
//
void Warehouse::restock(int product, int additional)
{
    counts[product] = counts[product]+additional;
}

// Check if a particular product is in stock
bool Warehouse::is_instock(int product)
{
    if (counts[product >=0)
    {
	    return true;
    }
}

// ask how many are on hand
int Warehouse::on_hand(int product)
{
    return counts[product];
}

//
// sell some amt of some product, return a bool if enough for sale
//
bool Warehouse::remove(int product, int amt)
{
    if (counts[product] > amt)
    {
	return true;
    }
    else
    {
	return false;
    }
}

//
// returns the maximum valid product id
//
int Warehouse::maxid()
{
	return NUM_PRODUCTS - 1;
}
//
// Which products need to be restocked?
// Pass in a restock level,
// the function fills in a bool array where
// true in position 0 => product 0 is below that level
// true in position 1 => product 1 is below that level
// ...
// return value is number of products that need restock
int Warehouse::need_restock(int minimum, bool isLow[])
{
    
}

//
// used internally - determine if the arg is a valid product id
//
bool Warehouse::valid_id(int product)
{
	// your code here
}

