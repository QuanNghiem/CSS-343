// file store.cpp
// Function definitions for the store class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#include "store.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class
// initialize store name to be empty string
Store::Store() : storeName("") {

}

//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed name
Store::Store(string name) : storeName(name) {}//end name Constructor

//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object store
Store::Store(const Store& rhs) {}//end copy constructor

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
Store::~Store() {}//end destructor

//-----------------------------------------------------------------------------
// createCustomers
// read infile and continue to create customers
// until the end of the file
// delete if no customers exist in file
void Store::createCustomers(istream& infile) {
	for (;;){
		Customer* cust = new Customer();
		cust->setData(infile);
		if (infile.eof()) {
			delete cust;
			cust = NULL;
			break;
		}
		customerList[cust->getCustomerID()] = *cust;
		delete cust;
		cust = NULL;
	}
}
//-----------------------------------------------------------------------------
// createProduct
// read infile and continue to create products
// until the end of the file
// delete if no products exist in file
void Store::createProduct(istream& infile){
	char cmd = ' ';
	char dum = ' ';
	int number;
	for (;;){
		infile >> cmd >> dum;
		if (infile.eof()) break;

		Product * newMovie = hashTable.createMovie(cmd, infile);

		if (newMovie != NULL){
			infile >> number;
			newMovie->setData(infile);
			newMovie->setMaxCopies(number);
			bool inserted = productList[hashTable.getHash(cmd)]
				.insert(newMovie);

			if (!inserted){
				delete newMovie;
				cout << "Not Inserted" << endl;
			}
		}
		newMovie = NULL;
		delete newMovie;
	}
}
//----------------------------------------------------------------------------
// processTransactions
// read infile and customer history and products are updated
// depending on each transaction
void Store::processTransactions(istream& infile) {
	char cmd = ' ';
	char movCh = ' ';
	char medCh = ' ';
	int custID = 0;
	bool found = false;
	string mediaType = "";
	char EOL = '\n';
	Product * productLocafion = NULL;
	Customer * tempCust = NULL;
	Product *  tempItem = NULL;

	for (;;){
		infile >> cmd;
		if (infile.eof()) break; //check for end of file

		if (cmd == 'I'){
			displayProduct();
			cmd = ' ';
		}
		else if (infile.get() == EOL)
			cmd = ' ';
		else {
			Transaction * newTransaction = hashTable
							.createTransaction(cmd, infile);

			if (newTransaction != NULL){
				infile >> custID;

				if (infile.eof()) break;

				if (lookUpCustomer(custID)){
					tempCust = &customerList[custID];

					bool isHistory = newTransaction->
								setData(mediaType, productLocafion, tempCust);

					if (infile.get() != EOL && isHistory){


						infile >> medCh;

						mediaType = hashTable.getMediaType(medCh);


						if (mediaType != ""){  //movie genre

							infile >> movCh;

							tempItem = hashTable.createMovie(movCh, infile);

							if (tempItem != NULL){
								tempItem->setCmd(infile);

								found = productList[hashTable.
									getHash(movCh)].
									retrieve(*tempItem, productLocafion);

								if (found == false)
								{
									cout << "ERROR: Invalid Movie Request!"
										<< tempItem->getItem() << endl;
								}//end if
								delete tempItem;
								tempItem = NULL;

								bool found2 = newTransaction->
									setData(mediaType, productLocafion, tempCust);

								if ((found && found2) && mediaType != ""){
									customerList[custID]
										.addTransaction(*newTransaction);

								}
								delete newTransaction;
								newTransaction = NULL;
							}
							else{
								cout << "ERROR: " << movCh
									 << " not Found!" << endl;

								if (newTransaction != NULL)
									delete newTransaction;
								newTransaction = NULL;
							}

							string temp;
							getline(infile, temp, EOL);
							delete tempItem;
							tempItem = NULL;

						}
						else{
							string temp;
							getline(infile, temp, EOL);

							cout << "ERROR: Invalid Code " << medCh << endl;

							if (newTransaction != NULL)
								delete newTransaction;
							newTransaction = NULL;
						}
					}
					else {
						if (newTransaction != NULL)
							delete newTransaction;
						newTransaction = NULL;
					}
				}
				else {
					cout << "Error: Invalid Customer ID " << custID << endl;

					if (newTransaction != NULL)
						delete newTransaction;
					newTransaction = NULL;

					string temp;
					getline(infile, temp, EOL);
				}
			}
			else {
				cout << "ERROR: Invalid Action Code " << cmd << endl;

				if (newTransaction != NULL)
					delete newTransaction;
				newTransaction = NULL;
			}
		}

		found = false;
		custID = 0;
		productLocafion = NULL;
		tempCust = NULL;
		tempItem = NULL;
	}//end for
}

//----------------------------------------------------------------------------
// display
// displays every product in the store
void Store::display() {
	displayCustomer();
	displayProduct();
}
//----------------------------------------------------------------------------
// displayProduct
// displays products in the store and their stocks

void Store::displayProduct() const {
	if (storeName != ""){
		cout
		<< "--------------------------------------------------------------"
		<< endl;
		cout << "Product for " << storeName << endl;
		cout
		<< "--------------------------------------------------------------"
		<< endl;
	}//end if

	for (int i =  MAX_INVENTORY-1; i>=0; i--){
		if (!productList[i].isEmpty()){

			productList[i].inorderDisplay(productList[i].getRoot());
		cout << endl;
		}//end if
	}//end for
}
//----------------------------------------------------------------------------
// displayAllCustomer
// displays all customers in the store
void Store::displayCustomer() const {
	for (int i = MAX_CUSTOMER -1; i>=0; i--){
		if (lookUpCustomer(i)){
			getCustomer(i).display();
		}
	}
}
//----------------------------------------------------------------------------
// lookUpCustomer
// Check if customer is valid in the store based on id number
bool Store::lookUpCustomer(int IDNumber) const {
	if (customerList[IDNumber].getCustomerID() == -1){
		return false;
	}
	else
		return true;
}
//----------------------------------------------------------------------------
// getBusinessName
// returns the name of store
string Store::getBusinessName() const {
	return storeName;
}
//----------------------------------------------------------------------------
// getCustomer
// returns the customer in list based on id number
Customer Store::getCustomer(const int IDNumber) const {
	return customerList[IDNumber];
}
