//-------------poly.cpp----------------------------------------------------
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

#include "poly.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//---------------------default constructor--------------------------------
// default constructor: No parameters, creates Poly object of size 1 with
// its only value set to 0
//------------------------------------------------------------------------
Poly::Poly() : size(1)
{
	polyPtr = new int[1];
	polyPtr[0] = 0;
} //end of default constructor

//---------------------overloaded constructor-----------------------------
// overloaded constructor: create an a Poly object with an array of size 1
// with coeff parameter as its only value
//------------------------------------------------------------------------
Poly::Poly(int coeff) :	size(1)
{
	polyPtr = new int[1];
	polyPtr[0] = coeff;
} //end of overloaded constructor

//---------------------overloaded constructor-----------------------------
// overloaded constructor: Creates a Poly object with its size set to
// power + 1 and coeff as the array's last indexed value
//------------------------------------------------------------------------
Poly::Poly(int coeff, int power) : size(power + 1)
{
	polyPtr = new int[size];
	//populate the array with 0
	for (int i = 0; i < size; i++)
	{
		polyPtr[i] = 0;
	}
	polyPtr[power] = coeff;
} //end of overloaded constructor

//---------------------copy constructor-------------------------------------
// copy constructor: creates an exact deep copy of the Poly object passed in
//--------------------------------------------------------------------------
Poly::Poly(const Poly &orig)
{
	size = orig.size;
	polyPtr = new int[size];

	for (int i = 0; i < size; i++) //Copy array values to new Object
	{
		polyPtr[i] = orig.polyPtr[i];
	}
} //end of copy constructor

//---------------------destructor--------------------------------------
// destructor:  delete polyPtr and set to NULL
//---------------------------------------------------------------------
Poly::~Poly(void)
{
	delete[] polyPtr;
	polyPtr = NULL;
} //end of destructor

//---------------------getCoeff---------------------------------------------
// Retrieve the value of the specified index, which is represented by power.
// If value out of range then 0 is returned
//--------------------------------------------------------------------------
int Poly::getCoeff(int power)
{
	if ((power >= 0) && (power < size)) //Make sure values in range
	{
		return this->polyPtr[power];
	}
	else
	{
		return 0;
	}
} //end of getCoeff

//---------------------setCoeff-------------------------------------------
//set the coeff to a new value corresponding with the power
//------------------------------------------------------------------------
void Poly::setCoeff(int coeff, int power)
{
	if (power >= 0)
	{
		if (power + 1 > size)
		{
			int *temp = new int[power + 1]; //Create new array
			for (int i = 0; i < size; i++)
			{
				temp[i] = polyPtr[i]; //Copy old values into temp
			}
			for (int j = size; j < (power + 1); j++)
			{
				temp[j] = 0; //Fill remaining array space with zero's
			}
			temp[power] = coeff; //set coeff value in specified location
			delete[] polyPtr; //Delete and NULL to reserve space
			polyPtr = NULL;
			polyPtr = temp; //Copy all values from temp to polyPtr
			temp = NULL;
			size = power + 1; //set new size
		}
		else
			{
			polyPtr[power] = coeff;
			}
	}
} //end of setCoeff

//---------------------overloaded operator >>-------------------------------------------
// overloaded >>: Input the contents of the array which represents a
// polynomial. Input is formatted to look like coeff power. Ends with -1 -1.
//--------------------------------------------------------------------------------------
istream& operator>>(istream& input,Poly& rhs){
  for (int i=0; i < rhs.size; i++)
    rhs.polyPtr[i] = 0;
  while (!input.eof()){
    int tempCoeff = 0, tempPower = 0;
    input >> tempCoeff >> tempPower;
    if (tempPower < 0 )
      break;
    if (tempCoeff != 0) rhs.setCoeff(tempCoeff,tempPower);
  }//end while

  return input;
} //end of overloaded operator >>

//---------------------overloaded operator <<--------------------------------------------
// overloaded <<: Outputs the contents of the array which represents a
// polynomial. If the array is empty then " 0" is output. All output
// is formatted to look like a regular polynomial expression. If array is Null, return 0
//---------------------------------------------------------------------------------------
/*
ostream& operator<<(ostream &output, const Poly &obj)
{
	if (obj.polyPtr == NULL)
	{
		output << " 0";
		return output;
	}
	bool allZeroArrayFlag = true; //Flag to indicate empty array
	//Loop through poly array
	for (int i = obj.size - 1; i >= 0; --i)
	{
		if (obj.polyPtr[i] != 0) //check for zero
		{
			allZeroArrayFlag = false; //If all zeros, the boolean will remain true at the end of loop
			if (i != obj.size - 1)
			{
				output << " "; //No blank at start
			}
			if (obj.polyPtr[i] > 0) //Display "+" if positive coeff
			{
				output << "+";
			}
			if (i == 1) //Chooses correct output for polynomial
			{
				if (obj.polyPtr[i] == 1)
				{
					output << "x"; //No coeff 1 before power
				} else if (obj.polyPtr[i] == -1)
				{
					output << "-x"; //No coeff -1 before power
				} else
				{
					output << obj.polyPtr[i] << "x";
				}
			}
			else if (i == 0)
			{
				output << obj.polyPtr[i]; //No power, output coeff
			}
			else
			{
				if (obj.polyPtr[i] == 1)
				{
					output << "x^" << i; //No coeff 1 before power
				}
				else if (obj.polyPtr[i] == -1)
				{
					output << "-x^" << i; //No coeff -1 before power
				}
				else
				{
					output << obj.polyPtr[i] << "x^" << i;
				}
			}
		}
	}
	if (allZeroArrayFlag) //If empty polynomial display " 0"
	{
		output << " 0";
	}
	return output;
} //end of overloaded operator <<
*/

ostream &operator<<( ostream &out, const Poly &rhs ) {
    if (rhs.size == 0 && rhs.polyPtr[0] == 0) out << " 0";
    else
      for (int i = rhs.size -1; i >=0 ; i--) {
        if (rhs.polyPtr[i] != 0) {
          out << " ";
          if (rhs.polyPtr[i] > 0) out << "+";
          out << rhs.polyPtr[i];
          if (i > 0) out << "x";
          if (i > 1) out << "^" << i;
        }
    }
    return out;
}

//---------------------overloaded operator + --------------------------------------------
//overload operator + : add the content of two polynomial
//---------------------------------------------------------------------------------------
Poly Poly::operator +(const Poly& rhs)
{
	if (this->size > rhs.size)
	{
		Poly result(*this);

		for (int i = 0; i < rhs.size; i++)
		{
			result.polyPtr[i] = this->polyPtr[i] + rhs.polyPtr[i];
		}
		return result;
	}
	else
	{
		Poly result(rhs);

		for (int i = 0; i < this->size; i++)
		{
			result.polyPtr[i] = this->polyPtr[i] + rhs.polyPtr[i];
		}
		return result;
	}
} //end of overloaded operator +

//---------------------overloaded operator += -------------------------------------------
//overloaded +=: current object = current object + parameter
//---------------------------------------------------------------------------------------
Poly& Poly::operator +=(const Poly& rhs)
{
	*this = *this + rhs;
	return *this;
} //end of overloaded operator +=

//---------------------overloaded operator - -------------------------------------------
//overload operator - : subtract the content of two polynomial
//---------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly& rhs)
{
	int maxSize; //Size of larger array
	int smallestSize; //Size of smaller array

	if (size < rhs.size) //Determine the correct size for calculations
	{
		maxSize = rhs.size;
		smallestSize = this->size;
	}
	else
	{
		maxSize = this->size;
		smallestSize = rhs.size;
	}

	Poly result(0, maxSize - 1); //New Poly object to hold all values

	for (int i = 0; i < smallestSize; i++)
	{
		result.polyPtr[i] = (this->polyPtr[i] - rhs.polyPtr[i]);
	}

	while (smallestSize < rhs.size) //Add remaining values left in RHS to array
	{
		if (rhs.polyPtr[smallestSize] > 0) //Adjust remaining signs for coeff
		{
			result.polyPtr[smallestSize] = 0 - rhs.polyPtr[smallestSize];
		}
		else
		{
			result.polyPtr[smallestSize] = rhs.polyPtr[smallestSize];
		}
		smallestSize++;
	}

	while (smallestSize < this->size) //Add remaining values left in LHS to array
	{
		result.polyPtr[smallestSize] = this->polyPtr[smallestSize];
		smallestSize++;
	}
	return result;
} //end of overloaded operator -

//---------------------overloaded operator -= -------------------------------------------
//overloaded -=: current object = current object - Poly parameter
//---------------------------------------------------------------------------------------
Poly& Poly::operator -=(const Poly& rhs) {
	*this = *this - rhs;
	return *this;
} //end of overloaded -=

//---------------------overloaded operator * -------------------------------------------
//overloaded *: multiplies two Poly objects together
//---------------------------------------------------------------------------------------
Poly Poly::operator *(const Poly& rhs)
{
	int arraySize = (this->size + rhs.size - 2); //Size of new array
	Poly temp(0, arraySize); //New Poly size holds all values
	for (int i = 0; i < size; i++) //Populate temp with calculations
	{
		for (int j = 0; j < rhs.size; j++)
		{
			temp.polyPtr[i + j] += (polyPtr[i] * rhs.polyPtr[j]);
		}
	}
	return temp;
} //end of overloaded operator *

//---------------------overloaded operator *= -------------------------------------------
//overloaded *=: current object = current object * Poly parameter
//---------------------------------------------------------------------------------------
Poly& Poly::operator *=(const Poly& rhs)
{
	*this = *this * rhs;
	return *this;
} //end of overloaded operator *=

//---------------------overloaded operator == -------------------------------------------
// overloaded ==: true if current object is == parameter, otherwise false
//---------------------------------------------------------------------------------------
bool Poly::operator==(const Poly& rhs)const
{
	//set max to highest exponent of lhs or rhs
	int max = (this->polyPtr[this->size -1] >= rhs.polyPtr[rhs.size -1] ?
			this->polyPtr[this->size -1] : rhs.polyPtr[rhs.size -1]);
	//look at each term in first and second polynomial
	//return false if they're not the same
	for (int i = 0; i <= max; i++)
	{
		int number1 = i <= this->polyPtr[this->size -1] ? this->polyPtr[i] : 0;
		int number2 = i <= rhs.polyPtr[rhs.size -1]
			? rhs.polyPtr[i] : 0;
		if (number1 != number2)
			return false;
	}
	return true;
} //end of overloaded operator ==

//---------------------overloaded operator != -------------------------------------------
// overloaded !=: true if current object is != parameter, otherwise false
//---------------------------------------------------------------------------------------
bool Poly::operator !=(const Poly& rhs) const
{
	return !(*this == rhs);
} //end of overloaded operator !=

//---------------------overloaded operator = -------------------------------------------
// overloaded =: assigns LHS to be RHS
//---------------------------------------------------------------------------------------
Poly& Poly::operator =(const Poly& rhs)
{
	//Assigned to itself, ignore
	if (*this == rhs)
	{
		return *this;
	}
	else
	{
		delete[] polyPtr;
		polyPtr = NULL;
		size = rhs.size;
		polyPtr = new int[size];

		for (int i = 0; i < size; i++) //Assign value from LHS to RHS
		{
			polyPtr[i] = rhs.polyPtr[i];
		}
	}
	return *this;
} //end of overloaded operator =
