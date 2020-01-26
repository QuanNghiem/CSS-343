// file history.cpp
// Function definitions for the history class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "history.h"
#include "customer.h"


//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class
// Sets the transaction type to be of type history(display)
History::History() : Transaction(){
	transactionType = "History";
}

//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
History::History(const History& rhs) {
	transactionType = rhs.transactionType;
	mediaType = rhs.mediaType;
	product = rhs.product;
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
History::~History(){}// end destructor

//-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text
bool History::setData(string media, Product * item, Customer * aCustomer) {
	aCustomer->displayCustomerHistory();

	return false;
}//end setData
//-----------------------------------------------------------------------------
// create
// Makes a history object, which returns as a transaction pointer
Transaction * History::create() {
	return new History();
}//end create
