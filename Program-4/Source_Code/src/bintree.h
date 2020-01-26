// file bintree.h
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

#ifndef BINTREE_H
#define BINTREE_H
#include "movie.h"
struct Node;

//---------------------------------------------------------------------------
// BinTree Class: Contains all declarations of functions and data members
//				   needed for BinTree class
// Implementation
//		** Private structure Node holding pointer to data, left child,
//       and right child.
//		** functions transferring data from tree to array and array to tree
// Assumptions
//		**The Product already have all the co parision operation, input,
//      output with istream and ostream.
//---------------------------------------------------------------------------

class BinTree
{

	friend ostream& operator<<(ostream& output, BinTree& tree);
	struct Node;

public:
	//const
	BinTree();
	BinTree(const BinTree&);
	//destruct
	~BinTree();
	//utility funcs
	bool insert(Product* insertMovie);
	bool isEmpty() const;
	void makeEmpty();
	bool retrieve(const Product& dataItem, Product*& dataFound) const;
	void retrieveHelper(Node* curPtr,
		const Product & dataItem, Product*& dataFound) const;
	void inorderDisplay(Node * current) const;
	Node * getRoot() const;
private:
	//binary tree 
	struct Node
	{
		Product* product;
		Node* left, *right;
	};
	Node *root;
	void inOrderDisplayHelper(Node* current) const;
	void destroyTree(Node*& tree);
};
#endif
