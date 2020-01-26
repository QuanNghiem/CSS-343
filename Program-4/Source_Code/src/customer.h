// file customer.h
// Function definitions for the customer class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "movie.h"
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

//----------------------------------------------------------------------------
// Class: Customer
// Object hold information used to identify a customer, rental information,
// transaction information, and history information. Objects are
// created from text file and stored in array inside of store.
//----------------------------------------------------------------------------

class Customer {
public:
	//constructors
	Customer();
	Customer(istream&);
	Customer(const Customer&);
	//destructor
	virtual ~Customer();
	//mutator
	void setData(istream& infile);
	void displayCustomerHistory() const;
	void addTransaction(Transaction );
	virtual void display() const;
	//accessor
	int getCustomerID() const;
	string getFirstName() const;
	string getLastName() const;
	//operator
	virtual bool operator==(const Customer& rhs) const;	
	virtual bool operator!=(const Customer& rhs) const;
private:
	int id;
	string firstName;
	string lastName;
	vector<Transaction> transactionHistory;

};

#endif
