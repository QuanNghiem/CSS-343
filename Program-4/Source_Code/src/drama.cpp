// file drama.cpp
// Function definitions for the drama class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "drama.h"
//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

DramaMovie::DramaMovie() : Movie(), GENRE("DRAMA") {
}

DramaMovie::DramaMovie(const DramaMovie& rhs) {
	title = rhs.title;
	director = rhs.director;
	year = rhs.year;
}
//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
DramaMovie::~DramaMovie() {}
//-----------------------------------------------------------------------------
// display
// Displays one line of the title, director, and year

void DramaMovie::display() const {
	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		<< setw(5) << year << endl;
}

//-----------------------------------------------------------------------------
// displayHeader
// For displaying categories of movies, when the subclass does not override, 
// this will be used since all movies have these data sets

void DramaMovie::displayHeader() const {
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *YEAR*  " <<
	endl;
	cout <<
	"---------------------------------------------------------------------"
		<< endl;
}


//-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text;
// director, title, actor, and year

void DramaMovie::setData(istream& infile) {
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;

}
//-----------------------------------------------------------------------------
// setCmd
// Sets the class's data members to the infile text;
// but for the command data, date and famous actor only

void DramaMovie::setCmd(istream& infile) {
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');
}
//-----------------------------------------------------------------------------
// operator==
// Checks to see which object is ==, that way the program can sort
// the objects correctly into the BST

bool DramaMovie::operator==(const Product& rhs) const{
	//cast Product down to DramaMovie
	const DramaMovie& dramaMovie = static_cast<const DramaMovie&>(rhs);

	return (title == dramaMovie.title && director == dramaMovie.director);
}
//-----------------------------------------------------------------------------
// operator<
// Checks to see which object is smaller, that way the program can sort
// the objects correctly into the BST

bool DramaMovie::operator<(const Product& rhs) const {
	const DramaMovie& dramaMovie = static_cast<const DramaMovie&>(rhs);

	if (director < dramaMovie.director){
		return true;
	}
	else if (director == dramaMovie.director){
		return (title < dramaMovie.title);
	}
	else
		return false;
}
//-----------------------------------------------------------------------------
// create
// Makes a Classic object, which returns as a Product pointer.

Product * DramaMovie::create() {
	 return new DramaMovie();
 }
