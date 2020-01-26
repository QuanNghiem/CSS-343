// file return.h
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

#ifndef _RETURN_H_
#define _RETURN_H_
#include "transaction.h"

//----------------------------------------------------------------------------
// Class: Return
// return object, child of transaction. Used when processing items within
// store. Each object contains all data members contained 
// in a transaction object and functions needed to modify
// data and display a return object.
//----------------------------------------------------------------------------

class Customer;		//forward declaration
class Return : public Transaction {

public:
	//constructor
	Return();
	//copy constructor
	Return(const Return&);
	virtual ~Return(); //end destructor
	virtual bool setData(string, Product *, Customer *);
	virtual void display() const;
	virtual Transaction * create(); //create new return object

};

#endif
