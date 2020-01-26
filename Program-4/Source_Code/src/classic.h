// file classic.h
// Function definitions for the classic class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#ifndef _CLASSICMOVIE_H_
#define _CLASSICMOVIE_H_
#include <string>
#include "movie.h"

/*-----------------------------------------------------------------------------
Specific movie class for movies belonging to the Classic category.
Implementation:
 Adds members for release month and famous actor
 Classics are represented by a ‘C’
 Sorted by release date and then famous actor.
-----------------------------------------------------------------------------*/

class ClassicMovie : public Movie {

public:
	// Constructors
	ClassicMovie();
	ClassicMovie(const ClassicMovie& rhs);
	~ClassicMovie();
	// the two different setData funcs for different text file reads
	void setData(istream& infile);
	virtual void setCmd(istream& infile);
	// displays for body and header
	void display() const;
	virtual void displayHeader() const;
	virtual bool operator==(const Product& rhs) const;
	virtual bool operator<(const Product& rhs) const;
	// creates the Classic object
	virtual Product * create();
private:
	// unique attributes for Classic movies
	string actorFirstName, actorLastName;
	int month;
	const string GENRE;
};


#endif
