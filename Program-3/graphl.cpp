#include "graphl.h"
//-------------graphl.cpp----------------------------------------------------
//Quan Nghiem CSS 343C
//Created on: Feb 17, 2019
//Last Modified: Feb 17, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created graph and Dijkstra method
//-------------------------------------------------------------------------
//Notes: assume that the array size is 100.
//-------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Default Constructor
// Creates the Graph object and initializes the edgeHead and visited variables
GraphL::GraphL()
{
	size = 0;
	for (int i = 1; i < MAXNODES; i++)
	{
		adjList[i].edgeHead = NULL;
		adjList[i].visited = false;
	}
}

//-----------------------------------------------------------------------------
// Destructor
// Calls makeEmpty function to free all memory allocations
GraphL::~GraphL()
{
	makeEmpty();
}

//-----------------------------------------------------------------------------
// buildGraph
// Fills the graph with nodes from the text file of data, stops reading the
// file if the size, from, and to is zero or negative.
void GraphL::buildGraph(ifstream& infile)
{
	// variables that hold the from and to node and their edge
	int from, to;

	// empty the current graph
	makeEmpty();

	// initializes the size
	infile >> size;

	// guards against empty text files and invalid sizes
	if (infile.eof() || size < 1)
	{
		return;
	}

	// the description of the location
	string s;
	getline(infile,s);

	// read graph node information,
	for (int i = 1; i <= size; i++)
	{
		adjList[i].data.setData(infile);
	}

	// goes on infinitely until the infile file hits the break case
	for (;;)
	{
		// read in the first node and its edge to the second node
		infile >> from >> to;

		// break case: line consisted of a zero
		if (from == 0 && to == 0)
		{
			return;
		}

		//Check validity
		if (from > 0 && to > 0 && from <= size && to <= size)
		{
			// puts the edge into the adjacency matrix
			insertEdge(from, to);
		}
	}
}

//-----------------------------------------------------------------------------
// insertEdge
// Used to insert the edge into the adjacency list, always inserts in the
// front of the list
void GraphL::insertEdge(const int from, const int to)
{
	// Creates a new edge node and plugs in the to node number
	EdgeNode* ptr = new EdgeNode;
	ptr->adjGraphNode = to;
	ptr->nextEdge = NULL;

	// connects the new edge node to the adjacency list
	EdgeNode* next = adjList[from].edgeHead;
	adjList[from].edgeHead = ptr;
	ptr->nextEdge = next;
}

//-----------------------------------------------------------------------------
// displayGraph
// Shows the graph's node and its descriptions and the edges per node
void GraphL::displayGraph() const
{
	// Check for empty graph
	if (size > 0)
	{
		cout << "Graph:\n";

		// Traverse through the graph
		for (int i = 1; i <= size; i++)
		{
			// prints out the node and its description
			cout << "Node " << i << "       " << adjList[i].data << endl;

			// pointer to the current head of the adjacency list
			EdgeNode* current = adjList[i].edgeHead;

			// traverse the list and prints out each edges
			while (current != NULL)
			{
				cout << "   edge " << i << " " << current->adjGraphNode << endl;
				current = current->nextEdge;
			}
		}
	}
	cout << endl;
}

//-----------------------------------------------------------------------------
// depthFirstSearch
// Visit every node and prints out the nodes that it first traverses, does not
// print visited nodes
void GraphL::depthFirstSearch()
{
	// Check for empty
	if ( size > 0 )
	{
		cout << "Depth-first ordering: ";

		// depth first search through all the adjacency list
		for (int v = 1; v <= size; v++)
		{
			// only visits each list once
			if (!adjList[v].visited)
			{
				//Call recursive helper
				dfsHelper(v);
			}
		}
	}
	cout << endl;
}

//-----------------------------------------------------------------------------
// dfsHelper
// Visits the adjacent nodes in the graph and prints out the first visited
void GraphL::dfsHelper(const int v)
{
	// node has been visited
	adjList[v].visited = true;
	cout << " " << v;

	// the adjacent node to v
	int w = 0;
	EdgeNode* current = adjList[v].edgeHead;

	// only traverses the list if the list contains nodes
	while (current != NULL)
	{
		w = current->adjGraphNode;
		if (!adjList[w].visited)
			dfsHelper(w);
		current = current->nextEdge;
	}
}

//-----------------------------------------------------------------------------
// makeEmpty
// Sets the head to NULL and visited to false, and the size back to zero.
void GraphL::makeEmpty()
{
	// Check for empty
	if (size > 0)
	{
		// traverses the entire graph array up to the size of the graph
		for (int i = 1; i <= size; i++)
		{
			// the head of the list
			EdgeNode* current = adjList[i].edgeHead;

			// deletes each node in the list
			while (current != NULL)
			{
				// makes sure to keep connection after deleting current node
				EdgeNode* next = current->nextEdge;
				delete current;
				current = next;
			}
			adjList[i].edgeHead = NULL;
			adjList[i].visited = false;
		}
		size = 0;
	}
}
