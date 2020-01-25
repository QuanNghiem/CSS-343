//-------------bintree.cpp----------------------------------------------------
//Quan Nghiem CSS 343C
//Created on: Jan 30, 2019
//Last Modified: Jan 31, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for Binary Search Tree object which store
//NodeDatas
//-------------------------------------------------------------------------
//Notes: assume that the array size for BST is 100.
//-------------------------------------------------------------------------

#ifndef BINTREE_H_
#define BINTREE_H_
#include "nodedata.h"

class BinTree
{
	friend ostream& operator<<(ostream&, const BinTree&); //Overloaded << operator

public:
	BinTree();	// constructor
	BinTree(const BinTree &);	// copy constructor
	~BinTree();	// destructor, calls makeEmpty

	//function used to modify BST
	bool insert(NodeData*);

	bool retrieve(const NodeData &, NodeData*&) const;

	int getHeight(const NodeData &) const; //Find depth of data in BST

	bool isEmpty() const; // true if tree is empty, otherwise false

	void makeEmpty(); // make the tree empty so isEmpty returns true

	void displaySideways() const; // provided, displays the tree sideways

	void bstreeToArray(NodeData*[]); //Puts BST into array of NodeData*

	void arrayToBSTree(NodeData*[]); //Puts NodeData* array into BST

	//Overloaded operator
	BinTree& operator=(const BinTree &);

	bool operator==(const BinTree &) const;

	bool operator!=(const BinTree &) const;

private:
	struct Node {
		NodeData* data; 					// pointer to data object
		Node* left; 						// left subtree pointer
		Node* right; 						// right subtree pointer
	};
	Node* root;								// root of the tree

	// utility functions
	void inOrderDisplay(Node*, ostream&) const; //Displays BST in-order

	bool isEqual(Node*, Node*) const; //Checks if two nodes equal

	void sideways(Node*, int) const; // provided, helper for displaySideways()

	int bstreeToArrayHelper(Node*, NodeData*[]); //bstToArray helper

	void retrieveHelper(Node*, const NodeData&, NodeData*&) const; //Helper

	void arrayToBSTreeHelper(NodeData*[], const Node*, int, int);

	void copyTree(Node*, Node*&) const; //Make a copy of BST

	void destroyTree(Node*&); //Destroy entire BST

	bool insertHelper(Node*&, NodeData*); //helper for insert

    int getHeightHelper(const NodeData&, Node*) const; // helper for getHeight

    int recursiveGetHeightHelper(Node*) const; // helper for the getHeighthelper
};

#endif /* BINTREE_H_ */
