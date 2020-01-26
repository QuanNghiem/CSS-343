// file customer.cpp
// Function definitions for the customer class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "customer.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class
// initialize id, names, and history
Customer::Customer() : id(-1), firstName(""), lastName(""){
	transactionHistory.reserve(10);	//sets a reserved size of the vector
}//end constructor

 //-----------------------------------------------------------------------------
 // Copy Constructor
 // Current object to copy to passed in object
 //	according to infile text
Customer::Customer(istream& infile) {
	setData(infile);
}//end constructor

 //-----------------------------------------------------------------------------
 // Copy Constructor
 // Current object to copy to passed in object
Customer::Customer(const Customer& rhs) {
	id = rhs.id;
	firstName = rhs.firstName;
	lastName = rhs.lastName;
} //end copy Constructor

//----------------------------------------------------------------------------
// Destructor
// Deallocates dynammically allocated memory back to the heap
//
Customer::~Customer(){
	for (int i = 0; i < (int)transactionHistory.size(); i++){
		//delete transactionHistory[i];
		//transactionHistory[i];
	}//end for
}//end destructor

 //-----------------------------------------------------------------------------
 // setData
 // Sets the class's data members to the infile text
void Customer::setData(istream& infile){
	infile >> id;
	if (infile.eof()) return;
	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}//end setData

 //-----------------------------------------------------------------------------
 // displayHistory
 // For displaying list of customer's transactions 
 // print no history if new customer
void Customer::displayCustomerHistory() const {
	cout << " **** Customer: " << id << " " << lastName << ", " << firstName
		<< endl;
	int size = transactionHistory.size();
	if (size > 0){
		for (int i = 0; i < size; i++){
			transactionHistory[i].display();
			transactionHistory[i].getItem()->display();
		}//end for
		cout << endl;
	}//end if
	else
		cout << "No Transactions for Customer" << endl;
	cout << endl;
} //end displayCustomerHistory

//-----------------------------------------------------------------------------
// addTransaction
// when customer makes a transaction, add it to the list
void Customer::addTransaction(Transaction trans) {
	transactionHistory.push_back(trans);
}//end addTransaction

//----------------------------------------------------------------------------
// Display
// displays the customer along with their history
//
void Customer::display() const {
	displayCustomerHistory();
}//end display

 //-----------------------------------------------------------------------------
 // accessor
 // Allows access to protected data in Customer class 
 //	for other classes to access

int Customer::getCustomerID() const { return id; }//end getCustomerID

//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in Customer class 
//	for other classes to access
string Customer::getFirstName() const { return firstName; }//end getFirstName

//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in Customer class 
//	for other classes to access
string Customer::getLastName() const { return lastName; }//end getLastName

//-----------------------------------------------------------------------------
// operator==
// Checks to see if id is equal 
bool Customer::operator==(const Customer& rhs) const {
	return (id == rhs.id);
} //end operator==


//-----------------------------------------------------------------------------
// operator!=
// Checks to see if id is is not equal 
bool Customer::operator!=(const Customer& rhs) const {
	return (id != rhs.id);
}//end operator!=
