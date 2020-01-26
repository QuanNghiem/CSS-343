
// file comedy.h
// Function definitions for the comedy class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#ifndef _COMEDYMOVIE_H_
#define _COMEDYMOVIE_H_
#include "movie.h"

/*-----------------------------------------------------------------------------
Specific movie class for movies belonging to the Comedy category.
Assumptions:
Comedy is represented by the letter ‘F’ in the data file
Sorted by title and then date.
-----------------------------------------------------------------------------*/

class ComedyMovie : public Movie {
public:
	// Constructors
	ComedyMovie();
	ComedyMovie(const ComedyMovie& );
	~ComedyMovie();//end destructor

	virtual void display() const;
	virtual void displayHeader() const;
	// for command data file
	virtual void setData(istream& );
	virtual void setCmd(istream& );
	virtual bool operator==(const Product& ) const;
	virtual bool operator<(const Product& ) const;
	// instantiates a Comedy object
	virtual Product * create(); //end create
private:
	const string GENRE;
};



#endif
