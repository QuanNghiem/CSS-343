// file product.cpp
// Function definitions for the product class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "product.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
//
Product::Product() : stockNumber(-1), maxStock(0){} //end constructor

//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
Product::Product(const Product& rhs) {} //end copy constructor

//----------------------------------------------------------------------------
// Destructor
// deallocates dynamically allocated memory and returns it to the heap
//
 Product::~Product() {} //end destructor

//-----------------------------------------------------------------------------
// setMaxCopies
// Sets the class's data members to the infile text
// product type, product
void Product::setMaxCopies(const int maxCopies) {
	maxStock = maxCopies;

	if (stockNumber < 0)
		stockNumber = maxCopies;
}//end setMaxCopies

//----------------------------------------------------------------------------
// Increase Copies
// increase stock

void Product::increaseCopies() {
	if (stockNumber != maxStock)
		stockNumber++;
}//end increaseCopies

//----------------------------------------------------------------------------
// Decrease Copies
// decreases stock

void Product::decreaseCopies() {
	if (stockNumber != 0)
		stockNumber--;
}//end decreaseCopies

//----------------------------------------------------------------------------
// getAmountIn
// return current stock
int Product::getAmountIn() {
	return stockNumber;
}//end getAmountIn

//----------------------------------------------------------------------------
// getAmountOut
// return the number of borrowed items
int Product::getAmountOut() {
	return maxStock - stockNumber;
}//end getAmountOut
