//-------------graphm.cpp----------------------------------------------------
//Quan Nghiem CSS 343C
//Created on: Feb 17, 2019
//Last Modified: Feb 17, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created graph and Djikstra method
//-------------------------------------------------------------------------
//Notes: assume that the array size is 100.
//-------------------------------------------------------------------------

#include "graphm.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Initializes TableType variables: visited = false, distance = inf,
// path = 0; and size to zero.
GraphM::GraphM() {
	// initializes all the variables in the graph, since its empty
	makeEmpty();
}

//-----------------------------------------------------------------------------
// makeEmpty
// Resets all variables to their initial values when the graph was empty
void GraphM::makeEmpty() {
	size = 0;
	// sets the nodes to a default value, of which the graph would be empty
	for (int source = 1; source < MAXNODES; source++) {
		// distance is initialize to the max number, 2^31-1
		for (int x = 1; x < MAXNODES; x++) {
			T[source][x].visited = false;
			T[source][x].dist = INF;
			T[source][x].path = 0;
			removeEdge(source, x);
		}
	}
}

//-----------------------------------------------------------------------------
// buildGraph
// Fills the graph with data. The data in the graph is filled with a size,
// descriptions, node 1 and 2, and an edge.
void GraphM::buildGraph(ifstream& infile) {
	// variables that hold the from and to node and their edge
	int from, to, edge;

	// empty the current graph
	makeEmpty();

	// initializes size of graph
	infile >> size;

	// guards against empty text files
	if (infile.eof())
	{
		return;
	}

	// the description of the location , should not exceed 50 characters
	if (size > 0)
	{
		string s;
		// the description of the location
		getline(infile,s);

		// read graph node information,
		for (int i = 1; i < size+1; i++)
		{
			adjList[i].setData(infile);
		}

		// goes on infinitely until the infile file hits the break case
		for (;;)
		{
			// read in the first node and its edge to the second node
			infile >> from >> to >> edge;

			// break case
			if (from == 0 && to == 0 && edge == 0)
			{
				return;
			}

			// populate the adjency matrix
			insertEdge(from, to, edge);
		}
	}
}

//-----------------------------------------------------------------------------
// insertEdge
// To insert the edge, set the location in the cost matrix to the edge value
void GraphM::insertEdge(const int from, const int to, const int cost)
{
	// Check validity
	if (from > 0 && to > 0 && cost > 0 && from <= size && to <= size)
	{
		C[from][to] = cost;
	}
}

//-----------------------------------------------------------------------------
// removeEdge
// To remove the edge, set the location in the cost matrix to infinity
void GraphM::removeEdge(const int from, const int to)
{
	// Check validity
	if (from < MAXNODES && to < MAXNODES)
	{
		C[from][to] = INF;
	}
}

//-----------------------------------------------------------------------------
// findShortestPath
// Uses Dijkstra's algorithm to find the shortest path between two nodes
void GraphM::findShortestPath()
{
	if ( size < 1)
	{
		return;
	}
	// v always hold the smallest path, w is the current path
	int v = 0, w = 0;

	// finds the shortest pathway from one node to the next node
	for (int source = 1; source <= size; source++)
	{
		// each source to itself is always zero
		T[source][source].dist = 0;

		// v reinitialize to zero after each iteration
		v = 0;

		// if v is -1 stop the loop and start over
		while (v != -1)
		{
			// finds the shortest current path and give it to v,
			findV(source, v);

			// marks the location of the shortest path
			T[source][v].visited = true;

			// shortest path was found, now set the pathways
			if (v != -1)
			{
				// traverse the T 2D array and update the shortest paths
				for (w = 1; w <= size; w++)
				{
					// checks if there is a shorter path from the v node
					if (!T[source][w].visited && C[v][w] != INF &&
						!(T[source][w].dist < T[source][v].dist + C[v][w]))
					{
						// sets the path to the shortest route
						T[source][w].path = v;
						T[source][w].dist = min(T[source][w].dist,
											(T[source][v].dist + C[v][w]));
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// findV
// Finds the smallest value in the current T[source][x] and sets v to x
// If not found, sets v to -1.
void GraphM::findV(const int source, int& v)
{
	// lowest value starts at infinity
	bool found = false;
	int lowestVal = INF;

	// compares every number in the T array to find v
	for (int i = 1; i <= size; i++)
	{
		// does not check visited nodes
		if (!T[source][i].visited)
		{
			// compares the T array to the lowest value
			if (T[source][i].dist < lowestVal)
			{
				// replaces with the lower value and set v
				lowestVal = T[source][i].dist;
				v = i;
				found = true;
			}
		}
	}
	// v is not found, v = -1
	if (!found)
	{
		v = -1;
	}
}

//-----------------------------------------------------------------------------
// displayAll
// Shows a table of data: description, from and to node, dijkstra's
// and the path.
void GraphM::displayAll()
{
	if (size > 0)
	{
		cout << "Description     "
		     << "From node To node Dijkstra's    Path\n";

		for (int row = 1; row <= size; row++)
		{
			// prints description, which is the source
			cout << adjList[row] << endl;

			for (int col = 1; col <= size; col++)
			{
				// not print if zero
				if (T[row][col].dist != 0)
				{
					// prints the from and to nodes
					cout << setw(20) << row << setw(9) << col;

					// distance is infinity
					if (T[row][col].dist == INF)
					{
						cout << setw(11) << "----" << endl;
					}

					else
					{
						cout << setw(9) << T[row][col].dist << setw(10);
						getPath(row, col);
						cout << endl;
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// getPath
// Gets the entire path from the node to the node
void GraphM::getPath(const int from, const int to) const
{
	// check validity
	if (from != to && T[from][to].path > 0)
	{
		getPath(from, T[from][to].path);
	}

	// prints out the pathway
	cout << " " << to;
}

//-----------------------------------------------------------------------------
// display
// Shows just one path from and to a node and displays the locations
// the path goes through
void GraphM::display(const int from, const int to)
{
	if (size < 1)
	{
		return;
	}
	// check validity
	if (from > 0 && to > 0 && from <= size && to <= size)
	{
		// print when distance is not infinity
		if (T[from][to].dist != INF)
		{
			cout << setw(5) << from
				 << setw(7) << to
				 << setw(10) << T[from][to].dist << setw(10);
			getPath(from, to);
			cout << endl;
			getPathData(from, to);
		}
		// otherwise, print "------"
		else
		{
			cout << setw(5) << from << setw(7) << to;
			cout << setw(10) << "----" << endl;
		}
	}
	// otherwise, print "-------"
	else
	{
		cout << setw(5) << from << setw(7) << to;
		cout << setw(10) << "----" << endl;
	}
}

//-----------------------------------------------------------------------------
// getPathData
// Recursively outputs the descriptions of each location the path goes through.
void GraphM::getPathData(const int from, const int to) const
{
	// check validity
	if (from != to && T[from][to].path > 0)
	{
		getPathData(from, T[from][to].path);
	}

	// prints the descriptions
	cout << adjList[to] << endl;
}
