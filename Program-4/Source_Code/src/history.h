// file history.h
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
#ifndef _HISTORY_H_
#define _HISTORY_H_
#include "transaction.h"

//----------------------------------------------------------------------------
// Class : History
// child of transaction, displays the history for specific customer.
//---------------------------------------------------------------------------
class Customer;
class History : public Transaction{
public:
	//construct
	History();
	//copy construct
	History(const History& rhs);
	~History(); //destructor
	//mutator
	virtual bool setData(string, Product *, Customer *);
	virtual Transaction * create();

};


#endif
