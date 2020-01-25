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

#include "bintree.h"

//----------------------------------BinTree------------------------------------------
// Default constructor: creates empty BST with root as NULL
BinTree::BinTree(): root(NULL)
{

}

//--------------------------------BinTree--------------------------------------------
// Copy constructor: Takes a reference to a BinTree object as its
// parameter, then creates an exact (deep) copy.
BinTree::BinTree(const BinTree& tree)
{
	copyTree(tree.root, root);
}

//------------------------------~BinTree----------------------------------------------
// Destructor: Calls makeEmpty to destroy the entire BST
BinTree::~BinTree()
{
	makeEmpty();
}

//-----------------------------------isEmpty-----------------------------------------
// Returns whether the BST is empty
bool BinTree::isEmpty() const
{
	return (root == NULL);
}

//----------------------------------makeEmpty------------------------------------------
// Call destroyTree to destroy the BST. destroyTree is a helper with does the
// recursive work. destroyTree code is from Frank Caranno, used with
// permission and slight modification
void BinTree::makeEmpty()
{
   destroyTree(root); //destroy entire BST
}

void BinTree::destroyTree(Node *& tree)
{
   // post-order traversal
   if (tree != NULL)
   {
      destroyTree(tree->left); //destroy left
      destroyTree(tree->right); //destroy right

      delete tree->data; //delete NodeData
      tree->data = NULL;
      delete tree; //Delete Node
      tree = NULL;
   }
}

//--------------------------------operator=--------------------------------------------
// overloaded =: Make LHS BinTree object become an exact (deep) copy of RHS BinTree object
BinTree& BinTree::operator=(const BinTree& rhs)
{
   if (this != &rhs)
   {
	   destroyTree(root);  // deallocate left-hand side
	   copyTree(rhs.root, root);  // copy right-hand side
   }
   return *this;
}

//--------------------------------operator==--------------------------------------------
// overloaded ==: Return true if two BST have same structure and data
// Uses is Equal as a helper for the recursive part
bool BinTree::operator==(const BinTree& rhs) const
{
   if(root == NULL && rhs.root == NULL) //Both are empty BST
   {
	   return true;
   }
   else
   {
	   return isEqual(root, rhs.root); //Else compare recursively
   }
}

bool BinTree::isEqual(Node* leftNode, Node* rightNode) const
{
  //Check whether the node data is the same
  //Safeguard against crash from comparison of empty BST, checks if NULL
  if ((leftNode != NULL && rightNode != NULL) && (*leftNode->data == *rightNode->data))
  {
     return true;
  }
  //Return false when reached the end
  if ((leftNode == NULL) || (rightNode == NULL))
  {
     return false;
  }
  //Check data and recursively search tree
  return ((leftNode->data == rightNode->data)
		  && isEqual(leftNode->left,  rightNode->left )
		  && isEqual (leftNode->right, rightNode->right));
}

//-------------------------------operator!=---------------------------------------------
// overloaded !=: Return true if two BST do NOT have same structure and data
bool BinTree::operator!=(const BinTree& rhs) const
{
	return !(*this == rhs);
}

bool BinTree::insert(NodeData *insertNode)
{
	return insertHelper(root, insertNode);
}

//-------------------------------insertHelper-------------------------------------------------
// insertHelper: takes in the root of the tree and a nodeData pointer, if its larger than root
// it searches down the right side if it's smaller it searches down left until empty leaf
// is found. If not found, dataPtr is equal to something in the tree
bool BinTree::insertHelper(Node*& curPtr, NodeData *dataptr)
{
   if (curPtr == NULL)
   {
      Node* temp = new Node;    // exception is thrown if memory is not allocated
      temp->data = dataptr;
      dataptr = NULL;
      temp->left = temp->right = NULL;
      curPtr = temp;
      return true;
   }
   else
   {
     if(*dataptr > *curPtr->data)
     {
       return insertHelper(curPtr->right, dataptr);
     }
     if(*dataptr < *curPtr->data)
     {
       return insertHelper(curPtr->left, dataptr);
     }
   }
   return false;
}

//-------------------------------retrieve---------------------------------------------
// Returns true if retrieve is found in BST and sets retrievePtr to pointer
// to the location found. Uses retrieveHelper as a helper for recursive part.
bool BinTree::retrieve(const NodeData& retrieve, NodeData*& retrievePtr) const
{
   retrieveHelper(root, retrieve, retrievePtr);

   if (retrievePtr != NULL) //Check is retrievePtr was changed
   {
	  return true;
   }
   else
   {
      return false; //If retrievePtr was not found then return false
   }
}

void BinTree::retrieveHelper(Node* current, const NodeData& retrieve, NodeData*& retrievePtr) const
{
   if (current == NULL) //Not Found
   {
      retrievePtr = NULL;
   }
   else if (retrieve == *current->data) //Item Found
   {
      retrievePtr = current->data;
   }
   else if(retrieve < *current->data) //Check left
   {
      retrieveHelper(current->left, retrieve, retrievePtr);
   }
   else //Check right
   {
      retrieveHelper(current->right, retrieve, retrievePtr);
   }
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const
{
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const
{
	if (current != NULL)
	{
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--)
		{
			cout << "    ";
		}

		cout << *current->data << endl; // display information of object
		sideways(current->left, level);
	}
}

//------------------------------copyTree----------------------------------------------
// Utility function that makes an exact copy of the BST
void BinTree::copyTree(Node* tree, Node *& newTree) const
{
   // pre-order traversal
   if (tree != NULL) // copy node
   {
      //Create new Node object for copy
      newTree = new Node;
      //Create new NodeData* object for copy and use existing data
      NodeData *temp = new NodeData(*tree->data);
      newTree->data = temp; //set data to be the same
      //go left in BST
      copyTree(tree->left, newTree->left);
      //go right in BST
      copyTree(tree->right, newTree->right);
   }
   else
   {
      newTree = NULL;  // copy empty tree
   }
}

//--------------------- getHeight -----------------------------------------
// Returns the height of a given node in a binary standard tree
// If the node given is a leaf than the height is 1
// Uses helper function getHeightHelper
int BinTree::getHeight(const NodeData &toFind) const
{
	return getHeightHelper(toFind, this->root);
}

//--------------------- getHeightHelper -----------------------------------------
// Helper function to getHeight
// Finds the specific node in the tree, if it exists
// Uses helper function recursiveGetHeightHelper
int BinTree::getHeightHelper(const NodeData& toFind, Node* current) const
{
    if (current == NULL)
    {
        return 0;   // node is not in tree, return height = 0
    }
    else if (*current->data == toFind)
    {
        return recursiveGetHeightHelper(current);   // node found
    }
    else
    {
        int left = getHeightHelper(toFind, current->left);  // search left
        int right = getHeightHelper(toFind, current->right);    // search right

        return max(left, right);
    }
}

//---------------------recursiveGetHeightHelper -----------------------------------------
// Helper function to getHeightHelper
// Determines the height of the root node
int BinTree::recursiveGetHeightHelper(Node* current) const
{
    if (current == NULL)
    {
        return 0; // have reached a leaf node
    }
    else
    {
        // counts the amount of levels in the tree from root node
        return 1 + max(recursiveGetHeightHelper(current->left), recursiveGetHeightHelper(current->right));
    }
}

//-----------------------------------bstreeToArray----------------------------------------
// Traverse tree in-order and stores Nodedata* in tempArray. Then makeEmpty
// is called to leave the tree empty. Uses a helper to determine location
void BinTree::bstreeToArray(NodeData* tempArray[])
{
   bstreeToArrayHelper(root, tempArray);
   makeEmpty(); //Make BST empty
}

int BinTree::bstreeToArrayHelper(Node* curPtr, NodeData *tempArray[])
{
	if(curPtr == NULL) //No data
	{
		return 0;
	}
	//Set location of left
	int left = bstreeToArrayHelper(curPtr->left, tempArray);

	NodeData *temp;
	temp = curPtr->data; // save the NodeData object to temp
	curPtr->data = NULL; // disconnect NodeData from Node
	*(tempArray + left) = temp; //tempArray points to temp
	temp = NULL; //Disconnect

	//set location of right
	int right = bstreeToArrayHelper(curPtr->right, tempArray + left + 1);

	//Return position
	return left + right + 1;
}

//-----------------------------arrayToBSTree----------------------------------------------
// Takes the NodeData* in tempArray and uses that data build a BST. Leaves
// tempArray filled with NULLS. Uses a helper function.
// ARRAYSIZE set as size of 100 here and in lab2.cpp
// Must know size of array to use this function
void BinTree::arrayToBSTree(NodeData* tempArray[])
{
   int height = 0;

   for(int i = 0; i < 100; i++) // Count how many indexes of array are used
   {
      if (tempArray[i] != NULL)
      {
    	  height ++;
      }
   }

   // Recursively call helper function to perform calculations
   arrayToBSTreeHelper(tempArray, root, 0, height-1);
}

void BinTree::arrayToBSTreeHelper(NodeData* tempArray[], const Node* curPtr, int start, int end)
{
	if (start > end)
		{
			curPtr = NULL;
		}
		else
		{
			int mid = (start + end) / 2;

			NodeData *temp;
			temp = tempArray[mid];
			tempArray[mid] = NULL;

			insert(temp);

			arrayToBSTreeHelper(tempArray, curPtr, start, mid - 1);
			arrayToBSTreeHelper(tempArray, curPtr, mid + 1, end);
		}
}

//-----------------------------operator<<----------------------------------------------
// overloaded <<: Displays the data from BST in-order. Uses helper function
// inorderDisplay to recursively traverse tree and print data.
ostream& operator<<(ostream& output, const BinTree& tree)
{
   tree.inOrderDisplay(tree.root, output); //call inOrderDisplay
   output << endl;
   return output;
}

void BinTree::inOrderDisplay(Node *curPtr, ostream &output) const
{
	if (curPtr == NULL)
	{
		return;
	}
	inOrderDisplay(curPtr->left, output);

	output << *(curPtr->data) << " ";

	inOrderDisplay(curPtr->right, output);
}

