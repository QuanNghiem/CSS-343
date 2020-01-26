// file transaction.h
// Function definitions for the transaction class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_
#include "movie.h"
//----------------------------------------------------------------------------
// Class: Transaction
// This transaction class contains all the functions that modify and display
// all the transaction happens in the store. Transaction has a Product
// point to specific movie, so we don't need time to find it. It also has
// transactionType.
//----------------------------------------------------------------------------
class Customer;
class Transaction {
public:
	Transaction(); // constructor
	Transaction(const Transaction& ); //copy constructor
	virtual ~Transaction(); // destructor

	virtual bool setData(string media, Product * item, Customer * aCustomer);	// setData
	virtual void display() const;// display
	virtual Transaction * create();

	string getMediaType();//get media type
	string getTransactionType();	// transaction type
	Product * getItem() const;	//pointer to Product Item

protected:
	string transactionType;
	string mediaType;
	Product * product;

};

#endif
