
// file classic.cpp
// Function definitions for the Classic class
//Team--: Cuong Vo, Jessela Budiman, Quan Nghiem
// CSS 343C
//Created on: Mar 3, 2019
//Last Modified: Mar 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for a movie rental store to
// automate their inventory tracking system
//-------------------------------------------------------------------------
#include "classic.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

ClassicMovie::ClassicMovie() : Movie(), actorFirstName(""), actorLastName(""),
							   month(0), GENRE("CLASSIC"){
}
//-----------------------------------------------------------------------------
// Copy Constructor
// Current object to copy to passed in object
ClassicMovie::ClassicMovie(const ClassicMovie& rhs){
	director = rhs.director;
	title = rhs.title;
	actorFirstName = rhs.actorFirstName;
	actorLastName = rhs.actorLastName;
	month = rhs.month;
	year = rhs.year;
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion
ClassicMovie::~ClassicMovie() {}

//-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text;
// director, title, actor, and year

void ClassicMovie::setData(istream& infile) {
	infile.get();
	getline(infile, director, ',');
	if (director.size() > 18){
		title.resize(18);
	}
	infile.get();
	getline(infile, title, ',');
	if (title.size() > 22){
		title.resize(22);
	}
	infile.get();
	infile >> actorFirstName >> actorLastName;
	infile >> month >> year;
}


//-----------------------------------------------------------------------------
// setCmd
// Sets the class's data members to the infile text;
// but for the command data, date and famous actor only
void ClassicMovie::setCmd(istream& infile) {
	infile >> month;
	infile >> year;
	infile >> actorFirstName;
	infile >> actorLastName;

}

//-----------------------------------------------------------------------------
// display
// Displays one line of the title, director, and year
void ClassicMovie::display() const {

	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		 << setw(3) << month << " "
		 << setw(5) << year << " "
		 << actorFirstName << " " << actorLastName << endl;
}

//-----------------------------------------------------------------------------
// displayHeader
// For displaying categories of movies, when the subclass does not override, 
// this will be used since all movies have these data sets
void ClassicMovie::displayHeader() const {
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *MO**YEAR* " <<
		"*ACTOR* " << endl;
	cout <<
	"---------------------------------------------------------------------"
		<< endl;
}
//-----------------------------------------------------------------------------
// operator==
// Checks to see which object is ==, that way the program can sort
// the objects correctly into the BST

 bool ClassicMovie::operator==(const Product& rhs) const{
	const ClassicMovie& classicMovie = static_cast<const ClassicMovie&>(rhs);

	return (year == classicMovie.year && month == classicMovie.month
		&& actorFirstName == classicMovie.actorFirstName &&
		actorLastName == classicMovie.actorLastName);
}

 //-----------------------------------------------------------------------------
 // operator<
 // Checks to see which object is smaller, that way the program can sort
 // the objects correctly into the BST

bool ClassicMovie::operator<(const Product& rhs) const {
	const ClassicMovie& classicMovie = static_cast<const ClassicMovie&>
																(rhs);

	if (year < classicMovie.year)
		return true;
	else if (year == classicMovie.year){
		if (actorFirstName < classicMovie.actorFirstName)
		{
			return true;
		}
		else if (actorFirstName == classicMovie.actorFirstName)
		{
			return (actorLastName < classicMovie.actorLastName);
		}
		else
			return false;
	}
	else
		return false;
}
//-----------------------------------------------------------------------------
// create
// Makes a Classic object, which returns as a Product pointer.

Product * ClassicMovie::create() {
	return new ClassicMovie();
}
