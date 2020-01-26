// file borrow.cpp
// Function definitions for the borrow class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "borrow.h"
//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class
// Sets the transaction type to be of type borrow
Borrow::Borrow() : Transaction() {
	transactionType = "Borrow";
}
//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
Borrow::Borrow(const Borrow& rhs) {
	transactionType = rhs.transactionType;
	mediaType = rhs.mediaType;
	product = rhs.product;
}
//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
Borrow::~Borrow() {}

//-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text
// if product is actually being borrowed, set the data
// makes sure the product is being borrowed properly to decrease stock
bool Borrow::setData(string media, Product * item, Customer * aCustomer){
	if (item != NULL){
		mediaType = media;
		product = item;

		if (mediaType != ""){
			product->decreaseCopies();
		}//end if

	}//end if
	return true;
}

//-----------------------------------------------------------------------------
// display
// Displays one line of the productType, and transactiontype
void Borrow::display() const{
	cout << mediaType << " " << transactionType << " ";
}

//-----------------------------------------------------------------------------
// create
// Makes a borrow object, which returns as a transaction pointer
Transaction * Borrow::create() {
	return new Borrow();
}
