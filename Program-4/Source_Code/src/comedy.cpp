// file comedy.cpp
// Function definitions for the comedy class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------

#include "comedy.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
ComedyMovie::ComedyMovie() : Movie(), GENRE("COMEDY") {
}//end constructor

 //-----------------------------------------------------------------------------
 // Copy Constructor
 // Current object to copy to passed in object
ComedyMovie::ComedyMovie(const ComedyMovie& rhs){
	title = rhs.title;
	year = rhs.year;
	director = rhs.director;
} //end copy constructor

  //-----------------------------------------------------------------------------
  // Destructor
  // Enables proper deletion
ComedyMovie::~ComedyMovie() {}//end destructor

//----------------------------------------------------------------------------
// Display
// displays the title, year, month, director, and actor for specific movie

void ComedyMovie::display() const {
	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		 << setw(5) << year << endl;
}//end display

//----------------------------------------------------------------------------
// Display Header
// displays specific header for comedy movie type
//
void ComedyMovie::displayHeader() const {
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *YEAR*  "
		<< endl;
	cout <<
	"---------------------------------------------------------------------"
		<< endl;
}//end displayHeaders

 //-----------------------------------------------------------------------------
 // setData
 // Sets the class's data members to the infile text;
 // director, title, actor, and year
void ComedyMovie::setData(istream& infile) {
	infile.get();
	getline(infile, director, ',');
	if (director.size() > 18){
		title.resize(18);
	}//end if

	infile.get();
	getline(infile, title, ',');
	if (title.size() > 22){
		title.resize(22);
	}//end if

	infile.get();
	infile >> year;
}
//-----------------------------------------------------------------------------
// setCmdData
// Sets the class's data members to the infile text;
// but for the command data, title and year only
void ComedyMovie::setCmd(istream& infile) {
	infile.get();
	getline(infile, title, ',');

	infile >> year;

}
//-----------------------------------------------------------------------------
// operator==
// Checks to see which object is ==, that way the program can sort
// the objects correctly into the BST
bool ComedyMovie::operator==(const Product& movieItem) const {
	//static cast down to ComedyMovie
	const ComedyMovie& comedyMovie = static_cast<const ComedyMovie&>(movieItem);
	return (title == comedyMovie.title && year == comedyMovie.year);
}
//-----------------------------------------------------------------------------
// operator<
// Checks to see which object is smaller, that way the program can sort
// the objects correctly into the BST

bool ComedyMovie::operator<(const Product& movieItem) const {
	//static cast down to ComedyMovie
	const ComedyMovie& comedyMovie = static_cast<const ComedyMovie&>(movieItem);

	if (title < comedyMovie.title)
		return true;
	else if (title == comedyMovie.title){
		return (year < comedyMovie.year);
	}
	else
		return false;
}//end operator <

 //-----------------------------------------------------------------------------
 // create
 // Makes a Comedy object, which returns as a Product pointer.

Product * ComedyMovie::create() {
	return new ComedyMovie();
}//end create
