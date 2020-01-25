//-------------graphm.h----------------------------------------------------
//Quan Nghiem CSS 343C
//Created on: Feb 17, 2019
//Last Modified: Feb 17, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created graph and Dijkstra method
//-------------------------------------------------------------------------
//Notes: assume that the array size is 100.
//-------------------------------------------------------------------------

#ifndef GRAPHM_H
#define GRAPHM_H

#include "nodedata.h"
#include <iostream>
#include <climits>
#include <iomanip>
#define MAXNODES 101
#define INF INT_MAX

class GraphM {

public:
	// default constructor: sets all the data sets in: C and T arrays
	GraphM();

	// fills the graph with data
	void buildGraph(ifstream&);

	// assigns an edge of two Nodes
	void insertEdge(const int, const int, const int);

	 // removes the edge of two Nodes
	void removeEdge(const int, const int);

	// uses Dijkstra algorithm
	void findShortestPath();

	void displayAll();

	void display(const int, const int);

private:
	struct TableType {
	bool visited;         // check if node has been visited
	int dist;             // currently known shortest distance from source
	int path;             // previous node in path of min distance
};

	NodeData adjList[MAXNODES];             // graph nodes information
	int C[MAXNODES][MAXNODES];              // Cost matrix
	int size;                               // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES];        // stores visited, distance, path

	// helper functions
	void makeEmpty();
	void findV(const int, int&);
	void getPath(const int, const int) const;
	void getPathData(const int, const int) const;
};

#endif
