// file product.h
// Function definitions for the product class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#ifndef _INVENTORY_H_
#define _INVENTORY_H_
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//----------------------------------------------------------------------------
// Class: Product
// parent class of all items stored within the store. contains all virtual
// and pure virtual methods necessary for transactions as well as setting data
// of child classes.
//----------------------------------------------------------------------------

class Product {
public:
	Product(); //constructor
	Product(const Product&); //copy constructor

	virtual ~Product(); //destructor
	virtual void setData(istream& ) = 0; //sets data of inventory itme
	virtual void setCmd(istream& ) = 0;	//addition information to set
	virtual void display() const = 0;	//display all data
	virtual void displayHeader() const = 0;
	virtual string getItem() const = 0;	//return the inventory item

	void setMaxCopies(const int);
	void increaseCopies();
	void decreaseCopies();
	int getAmountIn();		//return current stock
	int getAmountOut();		//return current stock

	virtual bool operator==(const Product&) const = 0;
	virtual bool operator<(const Product&) const = 0;
	virtual Product* create() = 0;
private:
	int stockNumber;
	int maxStock;
};

#endif
