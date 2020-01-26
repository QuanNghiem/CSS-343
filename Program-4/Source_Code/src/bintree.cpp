// file bintree.cpp
// Function definitions for the bintree class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "bintree.h"
//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class
// Sets the transaction type to
BinTree::BinTree() : root(NULL) {
}
//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
BinTree::BinTree(const BinTree& rhs){} //end copy constructor

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
BinTree::~BinTree(){
	if (root != NULL)
		makeEmpty();
}
//----------------------------------------------------------------------------
// Insert
// Inserts movie item inside of the tree as well as sets the number of copies
// the item inserted has
bool BinTree::insert(Product* insertMovie) {
	Node* newNode = new Node();
	newNode->product = insertMovie; //Link to current NodeData
	insertMovie = NULL; //Disconnect
	newNode->left = newNode->right = NULL;
	if (isEmpty())
	{
		root = newNode; //Empty, set as root
	}
	else
	{
		Node* current = root;
		bool inserted = false;

		// if data is less than current data, insert in left subtree,
		// otherwise insert in right subtree
		while (!inserted)
		{
			if (*newNode->product == *current->product) //Duplicate, dont insert
			{
				delete newNode;
				newNode = NULL;
				return false;
			}
			else if (*newNode->product < *current->product)
			{
				if (current->left == NULL)
				{
					current->left = newNode;
					inserted = true;
				}
				else
					current = current->left;
			}
			else {
				if (current->right == NULL)
				{
					current->right = newNode;
					inserted = true;
				}
				else
					current = current->right;
			}
		}
	}
	return true;
} //end insert

//----------------------------------------------------------------------------
// isEmpty
// Checks if the root is empty or not
bool BinTree::isEmpty() const {
	return (root == NULL);
} //end isEmpty

//----------------------------------------------------------------------------
// makeEmpty
// calls private method destroyTree() to clear all tree data
//
void BinTree::makeEmpty() {
	destroyTree(root);
} //end makeEmpty

//----------------------------------------------------------------------------
// destroyTree
// postorder deletion of nodes in the tree
void BinTree::destroyTree(Node*& tree){
	if (tree != NULL){
		destroyTree(tree->left); //destroy left
		destroyTree(tree->right); //destroy right

		delete tree->product; //delete NodeData
		tree->product = NULL;
		delete tree; //Delete Node
		tree = NULL;
	}
} //end destroyTree

//----------------------------------------------------------------------------
// Retrieve
// Find item within the tree by storing it in a node data item
bool BinTree::retrieve(const Product& dataItem, Product*& dataFound)
														const {
	retrieveHelper(root, dataItem, dataFound);

	if (dataFound != NULL)
		return true;
	else
		return false;
} // end retireve

//----------------------------------------------------------------------------
// retrieveHelper
// Recursive function called privately by retrieve aiding the search for data
// Item within tree
void BinTree::retrieveHelper(Node* curPtr, const Product & dataItem,
								Product*& dataFound) const {
	if (curPtr == NULL)
		dataFound = NULL;
	else if (dataItem == *curPtr->product){
		dataFound = curPtr->product;
	}
	else if (dataItem < *curPtr->product)
		retrieveHelper(curPtr->left, dataItem, dataFound);
	else
		retrieveHelper(curPtr->right, dataItem, dataFound);
}//end retrieveHelper

//----------------------------------------------------------------------------
// inOrderDisplay
// Displays all items in tree from lowest to highest prececdence
void BinTree::inorderDisplay(Node * current) const{
	if (current == root){
		current->product->displayHeader();
	}//end if

	if (current != NULL){
		inorderDisplay(current->left);

		cout << right << setw(2) << current->product->getAmountIn() << "  " <<
			left << setw(3) << current->product->getAmountOut() << " ";
		current->product->display();

		inorderDisplay(current->right);
	}//end if
}//end inorderDisplay

//----------------------------------------------------------------------------
// getRoot
// returns root of tree
BinTree::Node * BinTree::getRoot() const { return this->root; }//end getRoot
