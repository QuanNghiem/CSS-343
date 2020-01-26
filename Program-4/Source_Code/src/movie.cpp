
// file movie.cpp
// Function definitions for the movie class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "movie.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

Movie::Movie() : Product(), title(""), director(""), year(0) {
}

//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
Movie::Movie(const Movie& rhs){
	title = rhs.title;
	director = rhs.director;
	year = rhs.year;
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion

Movie::~Movie(){
}
//-----------------------------------------------------------------------------
// display
// Displays one line of the title, director, and year

void Movie::display() const {
	cout << title << " " << director
		<< " "
		<< year
		<< endl;
}
//-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text;
// director, title, actor, and year

void Movie::setData(istream& infile) {
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
}


//-----------------------------------------------------------------------------
// displayHeader
// For displaying categories of movies, when the subclass does not override, 
// this will be used since all movies have these data sets

void Movie::displayHeader() const {
	cout << " ****** MOVIE ITEM ***** "
		 << endl;
}

//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in movie class 
//	for other classes to access
string Movie::getItem() const {
	return title;
}
//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in movie class 
//	for other classes to access
string Movie::getDirector() {
	return director;
}

//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in movie class 
//	for other classes to access
string Movie::getTitle() {
	return title;
}

//-----------------------------------------------------------------------------
// accessor
// Allows access to protected data in movie class 
//	for other classes to access
int Movie::getYear() {
	return year;
}
