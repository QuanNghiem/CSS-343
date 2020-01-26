// file transaction.cpp
// Function definitions for the transaction class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "transaction.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class
Transaction::Transaction() :
		transactionType("Transaction"), mediaType(""), product(NULL)
{}

//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
Transaction::Transaction(const Transaction& rightSide){
	transactionType = rightSide.transactionType;
	mediaType = rightSide.mediaType;
	product = rightSide.product;
}
//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
Transaction::~Transaction(){}

//-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text
// product type, product
bool Transaction::setData(string media, Product * item,
													Customer * aCustomer){
	mediaType = media;
	product = item;
	return true;
}

//-----------------------------------------------------------------------------
// display
// Displays one line of the productType, and transactiontype
void Transaction::display() const {
	cout << mediaType << " " << transactionType << ": ";
}

//-----------------------------------------------------------------------------
// create
// Makes a transaction object, which returns as a transaction pointer
Transaction * Transaction::create() {
	return new Transaction();
}

//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in Transaction class 
//	for other classes to access
string Transaction::getMediaType() {
	return mediaType;
}
//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in Transaction class 
//	for other classes to access
string Transaction::getTransactionType() {
	return transactionType;
}

//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in Transaction class 
//	for other classes to access
Product * Transaction::getItem() const {
	return product;
}
