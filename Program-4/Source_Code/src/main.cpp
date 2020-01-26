// file main.cpp
// Function definitions for the main class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "store.h"

using namespace std;

//Test by creating store object
//Read files provided
int main(){

	Store teamStore("Team-- Store");
	ifstream infileCustomer("data4customers.txt");
	ifstream infileMovies("data4movies.txt");
	ifstream infileTransactions("data4commands.txt");


	if ((!infileCustomer) || (!infileMovies) || (!infileTransactions)) {
		cout << "File Could Not be Opened!" << endl;
		getchar();
		return 1;
	}

	teamStore.createCustomers(infileCustomer);
	teamStore.createProduct(infileMovies);
	teamStore.processTransactions(infileTransactions);

	return 0;

}
