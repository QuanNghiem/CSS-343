// file hashtable.h
// Function definitions for the hashtable class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#ifndef _FACTORY_H_
#define _FACTORY_H_
#define MAX_PRODUCT 26
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"

class Movie;
class Transaction;

using namespace std;

//----------------------------------------------------------------------------
// Class: hashTable
//  This class contain all the functions that is needed for product 
// and transaction objects. Uses predefined indexes for each  type
// and predefined maximum number of items per hash table.
//----------------------------------------------------------------------------

class HashTable {
public:
	//construct
	HashTable();
	//destruct
	~HashTable();
	//create
	Product * createMovie(char , istream& );
	Transaction * createTransaction(char , istream& );
	//accessors
	int getHash(char );
	string getMediaType(char );

private:
	//properties
	Product * storeProduct[MAX_PRODUCT];
	Transaction * transactionProduct[MAX_PRODUCT];
	string mediaType[MAX_PRODUCT];
	
	int hash(char ) const;
	//initialize
	void initProduct();
};

#endif
