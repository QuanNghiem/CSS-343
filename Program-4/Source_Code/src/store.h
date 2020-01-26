// file store.h
// Function definitions for the store class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#ifndef _STORE_H_
#define _STORE_H_
#define MAX_CUSTOMER 10000
#define MAX_INVENTORY 53
#include <fstream>
#include <vector>
#include "customer.h"
#include "hashtable.h"
#include "bintree.h"

//----------------------------------------------------------------------------
// Class: Store
// maintains all customers, inventory items, and transactions within class.
// creates, modifies, and manipulates all data involving these objects as well
//----------------------------------------------------------------------------

using namespace std;

class Store {

public:
	//constructor
	Store();
	//copy constructors
	Store(string );
	Store(const Store& );
	~Store();	//destructor
	//create
	void createCustomers(istream&);
	void createProduct(istream&);
	void processTransactions(istream&);
	//display functions in store
	void display();
	void displayProduct() const;
	void displayCustomer() const;
	bool lookUpCustomer(int) const;
	//accessors
	string getBusinessName() const;
	Customer getCustomer(const int) const;

private:
	//properties
	Customer customerList[MAX_CUSTOMER];
	BinTree productList[MAX_INVENTORY];
	vector<Transaction> storeTransactionHistory;
	HashTable hashTable;
	string storeName;
};

#endif
