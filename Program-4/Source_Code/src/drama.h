// file drama.h
// Function definitions for the drama class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#ifndef _DRAMAMOVIE_H_
#define _DRAMAMOVIE_H_
#include "movie.h"


//----------------------------------------------------------------------------
// Class: DramaMovie
// child of movie class, grandchild of inventory class. Holds data contained
// about specific drama movie items.
//  Assumptions:
// --Sorted by director and then title
// -- Classics are represented by a ‘D’
//----------------------------------------------------------------------------

using namespace std;

class DramaMovie : public Movie {
public:
	// Constructors
	DramaMovie();
	DramaMovie(const DramaMovie& ); //end copy constructor
	~DramaMovie(); //end destructor
	//display
	virtual void display() const;
	virtual void displayHeader() const;
	//mutators
	virtual void setData(istream& );
	virtual void setCmd(istream&);
	//operators
	virtual bool operator==(const Product& ) const;
	virtual bool operator<(const Product& ) const;
	// instantiates a Drama object
	virtual Product * create(); //end create

private:
	const string GENRE;	//set to drama
};


#endif
