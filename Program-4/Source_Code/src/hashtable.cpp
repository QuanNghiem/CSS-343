
// file hashtable.cpp
// Function definitions for the hashtable class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "hashtable.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class
// initialize hashtable for all transaction and products
HashTable::HashTable(){
	initProduct();
	storeProduct[getHash('C')] = new ClassicMovie();
	storeProduct[getHash('D')] = new DramaMovie();
	storeProduct[getHash('F')] = new ComedyMovie();
	transactionProduct[getHash('B')] = new Borrow();
	transactionProduct[getHash('H')] = new History();
	transactionProduct[getHash('R')] = new Return();
	mediaType[getHash('D')] = "DVD";
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
// Goes through hashtable and deletes all values
HashTable::~HashTable(){
	for (int i = 0; i < MAX_PRODUCT; i++){
		if (storeProduct[i] != NULL){
			delete storeProduct[i];
			storeProduct[i] = NULL;
		}
		if (transactionProduct[i] != NULL){
			delete transactionProduct[i];
			transactionProduct[i] = NULL;
		}
	}
}
//----------------------------------------------------------------------------
// createMovie
// creates specified movie object coordinating with array location
// type of movie and infile for movie
Product * HashTable::createMovie(char ch, istream& infile) {
	string temp;

	int index = hash(ch);
	if (storeProduct[index] == NULL)
	{
		getline(infile, temp, '\n');
		return NULL;
	}
	else{
		return storeProduct[index]->create();
	}
}
//----------------------------------------------------------------------------
// createTransaction
// creates specified transaction object coordinating with array location
// type of transaction and infile for transaction

Transaction * HashTable::createTransaction(char ch, istream& infile) {
	string temp;
	int index = hash(ch);
	if (transactionProduct[index] == NULL){
		getline(infile, temp, '\n');
		return NULL;
	}
	else
		return transactionProduct[index]->create();
}
//-----------------------------------------------------------------------------
// accessor
// Allows access to get data in hashtable 
//	for other classes to access

int HashTable::getHash(char ch){
	return hash(ch);
}
//-----------------------------------------------------------------------------
// accessor
// Allows access to get data in hashtable 
//	for other classes to access

string HashTable::getMediaType(char ch) {
	return mediaType[hash(ch)];
}

//-----------------------------------------------------------------------------
// hash
// hash function to input char passed in to the hashtable
int HashTable::hash(char ch) const{
	if (ch < 'a')
		return ch - 'A';
	else
		return 0;
}

//-----------------------------------------------------------------------------
// initHashTable
// initialize hashtable and its properties
void HashTable::initProduct(){
	for (int i = 0; i < MAX_PRODUCT; i++){
		storeProduct[i] = NULL;
		transactionProduct[i] = NULL;
		mediaType[i] = "";
	}
}
