// file borrow.h
// Function definitions for the borrow class
// Child of Transaction class. Each object contains all data
//  members contained in a transaction object and functions needed
//  to modify data and display a borrow object.
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#ifndef _BORROW_H_
#define _BORROW_H_
#include "transaction.h"

//----------------------------------------------------------------------------
// Class: Borrow
// Object that holds a "borrowed" item. Child of Transaction class. Each
// object contains all data members contained in a transaction object.
//----------------------------------------------------------------------------

class Customer;
class Borrow : public Transaction {
public:
	//constructor
	Borrow();
	//copy constructor
	Borrow(const Borrow& );
	~Borrow(); // destructor
	//mutator
	virtual bool setData(string , Product * , Customer * );
	virtual void display() const;
	virtual Transaction * create();

};


#endif
