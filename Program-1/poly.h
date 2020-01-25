//-------------poly.h----------------------------------------------------
//Quan Nghiem CSS 343C
//Created on: Jan 16, 2019
//Last Modified: Jan 20, 2019
//-------------------------------------------------------------------------
//Purpose: the program is created for Poly object which store polynomial
//in a dunamically allocated array
//-------------------------------------------------------------------------
//Notes: assumed that a Null Polynomial will be display as 0 in operator <<
//since +, -, * does not affect the other polynomial if do with a 0
//LHS, lhs: left hand side
//RHS, rhs: right hand side
//-------------------------------------------------------------------------

#ifndef POLY_H_
#define POLY_H_
#include <iostream>
using namespace std;

class Poly {
	friend istream & operator>>(istream &, Poly&); //overloading input stream operator
	friend ostream & operator<<(ostream &, const Poly&); //overloading output stream operator

public:
	//Constructors and Destructor
	Poly();
	Poly(int);
	Poly(int, int);
	Poly(const Poly&);
	~Poly();

	//Math operators
	Poly operator +(const Poly&);
	Poly operator -(const Poly&);
	Poly operator *(const Poly&);

	//Comparison
	bool operator ==(const Poly&) const;
	bool operator !=(const Poly&) const;

	//Assignment
	Poly& operator =(const Poly&);
	Poly& operator +=(const Poly&);
	Poly& operator -=(const Poly&);
	Poly& operator *=(const Poly&);

	void setCoeff(int, int);
	int getCoeff(int);
private:
	int* polyPtr; //pointer to array
	int size; //size of array
};

#endif /* POLY_H_ */
