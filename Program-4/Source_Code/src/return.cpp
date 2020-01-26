// file return.cpp
// Function definitions for the return class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "return.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
Return::Return() : Transaction() {
	transactionType = "Return";
}//end constructor

//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
Return::Return(const Return& rhs){
	mediaType = rhs.mediaType;
	transactionType = rhs.transactionType;
	product = rhs.product;
} //end copy constructor


//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
 Return::~Return(){
 }//end destructor

 //-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text
// if product is actually being returned, set the data
// makes sure the product is being return properly to increase stock
bool Return::setData(string media, Product * item, Customer * aCustomer) {

	if (item != NULL){
		mediaType = media;
		product = item;

		if (mediaType != "")
			product->increaseCopies();
	}//end if
	return true;
}//end setData

//----------------------------------------------------------------------------
// Display
// displays media type and transaction type
//
void Return::display() const{
	cout << mediaType << " " << transactionType << " ";
} //end display

//-----------------------------------------------------------------------------
// create
// Makes a return object, which returns as a transaction pointer
Transaction * Return::create() {
	return new Return();
} //create new return object
