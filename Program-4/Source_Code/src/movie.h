// file movie.h
// Function definitions for the movie class
//	for type of transaction
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#ifndef _MOVIE_H_
#define _MOVIE_H_
#include "product.h"

using namespace std;
//----------------------------------------------------------------------------
//  Class: Movie
// child of product class, and parent to classic, comedy, and drama.
// Adds director, title, and year of release on top of name
// Still pure virtual for some function, defined later by child classes
// Contains some default functions to be used by child classes
//----------------------------------------------------------------------------
class Movie : public Product {

public:
	//constructor
	Movie();
	//copy constructor
	Movie(const Movie& rhs);
	~Movie();	//destructor
	//display
	 virtual void display() const;
	 virtual void displayHeader() const = 0;
	 virtual void setData(istream& infile);
	 virtual void setCmd(istream&) = 0;	//addition information to set

	 virtual string getItem() const;	//return the product item
	 string getDirector(); //returns the director
	 string getTitle();	//returns the title
	 int getYear();		//returns the year

	 //these must be overridden in order to determin sort orders
	 virtual bool operator==(const Product&) const = 0;
	 virtual bool operator<(const Product&) const = 0;
	 virtual Product* create() = 0;

protected:
	string title;		//title of movie
	string director;	//director of movie
	int year;			//year created
};

#endif
