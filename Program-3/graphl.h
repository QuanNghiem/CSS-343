//-------------graphl.h----------------------------------------------------
//Quan Nghiem CSS 343C
//Created on: Feb 17, 2019
//Last Modified: Feb 17, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created graph and depth first search method
//-------------------------------------------------------------------------
//Notes: assume that the array size is 100.
//-------------------------------------------------------------------------

#include "nodedata.h"
#include <iostream>
#define MAXNODES 101
using namespace std;

class GraphL {

public:
	// constructor: makes an empty graph and initializes all the
	// edge heads to null and visited to false within the adjacency list
	GraphL();

	// destructor: frees all memory allocations from building the graph
	~GraphL();

	// takes in a file and builds the graph with the data inside it;
	void buildGraph(ifstream&);

	// shows the node and its description and the edges in that adjacency list
	void displayGraph() const;

	// traverses the list and goes through the smaller forward edges, then the
	// next edges, this happens recursively. If a node does not connect, it
	// will traverse it after its done with that iteration until all nodes
	// have been visited and printed
	void depthFirstSearch();

private:
struct EdgeNode;			// forward reference for the compiler
struct GraphNode {			// structure used for simplicity, use classes if desired
	bool visited;			// checks if node was visited or not
	EdgeNode* edgeHead;		// head of the list of edges
	NodeData data;          // contains the descriptions of each location
};
struct EdgeNode {
	int adjGraphNode;		// subscript of the adjacent graph node
	EdgeNode* nextEdge;
};
	// an array of lists, creates the graph
	GraphNode adjList[MAXNODES];
	int size;

	// helper functions
	void dfsHelper(const int);
	void makeEmpty();
	void insertEdge(const int, const int);

};
