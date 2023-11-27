// Other functions
// int getnum(string p);
//     Description:		converts a string into an integer value
//     Preconditions:	mut have characters + or -, and number 0-9, no spaces
//     Postcondition:	converted int is returned
//string getsign(int);
//     Description:		returns a + or - string
//     Preconditions:	s must be greater than or equal to 0, or less than 0
//     Postcondition:	+ or - is returned
//
//CLASSES PROVIDED:  Polynomial
//
// CONSTRUCTOR for the Polynomial class:
//   Customer()
//     Description:		constructor will initialize Polynomial objects
//     Preconditions:	none
//     Postcondition:	Data set to 0, false, or blank
//
// MODIFICATION MEMBER FUNCTIONS for the Polynomial class
//   void setc1 (const int value)
//     Description:		sets a value to the c1 variable
//     Precondition:	has to be an integer
//     Postcondition:	c1 has been set to value
//
//   void setc2 (const int value)
//     Description:		sets a value to the c2 variable
//     Precondition:	has to be an integer
//     Postcondition:	cw has been set to value
//
//	 void setc3 (const int value)
//	   Description:		sets a value to the c1 variable
//     Precondition:	has to be an integer
//     Postcondition:	c1 has been set to value
//
//	void setc3 (const int value)
//	   Description:		sets a value to the error variable
//     Precondition:	has to be an integer of either 0 or 1
//     Postcondition:	error has been set to value
//
//	void setpoly(const int, const int, const int)
//	   Description:		takes 3 integers of a polynomial, converts to strings, and combines them
//     Precondition:	error has to equal 0
//     Postcondition:	poly has completed polynomial used for output
//
//	void setwasset(const bool)
//	   Description:		sets wasset to value
//     Precondition:	has to be either true or false
//     Postcondition:	wasset is set to the bool given
//	
//
//  void display (void) const
//		Description:	print out the data in the current polynomial
//		Precondtion:	none
//		Postcondition:	prints all current values of data
//
// CONSTANT MEMBER FUNCTIONS for the People class
//   int getc1 (void) const
//		Description: return the value of the c1 variable
//		Preconditions: none
//		Postcondition: value of c1 is returned
//
//	int getc2 (void) const
//		Description: return the value of the c2 variable
//		Preconditions: none
//		Postcondition: value of c2 is returned
//
//	int getc3 (void) const
//		Description: return the value of the c3 variable
//		Preconditions: none
//		Postcondition: value of c3 is returned
//
//
//	int geterror (void) const
//		Description: return the value of the error variable
//		Preconditions: none
//		Postcondition: value of error is returned
//
//	bool getwasset (void) const
//		Description: return the value of the wasset variable
//		Preconditions: must be true or false
//		Postcondition: value of wasset is returned
//
//	string getpoly(void) const
//		Description: return the string of the poly variable
//		Preconditions: none
//		Postcondition: string poly is returned
//Overload operators
//
//friend Polynomial operator+ (const Polynomial&, const Polynomial&);
//		Description: overloads + operator to allow polynomial addition
//		Preconditions: none
//		Postcondition: returns a polynomial of the sum of the two parameters
//
//friend Polynomial operator- (const Polynomial&, const Polynomial&);
//		Description: overloads - operator to allow polynomial subtraction
//		Preconditions: none
//		Postcondition: returns a polynomial of the difference of the two parameters
//
// friend ostream& operator << (ostream&, const Polynomial&);
//		Description: overloads << operator to allow polynomial output
//		Preconditions: none
//		Postcondition: prints polynomial in form of x^2+x+y
//
//friend istream& operator >> (istream&, Polynomial&);
//		Description: takes input in form of "zx^2+zx+z" by splitting into substrings and extractin int
//		Preconditions: must contain ^ character, numbers  0-9, and no spaces
//		Postcondition: assigns values to c1, c2, and c3 and gives values for + and - to work with

#ifndef POLY_H
#define POLY_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
int getnum(string p, int neg);
string getsign(int);
class Polynomial
{
  public:
    // CONSTRUCTOR
    Polynomial();
    
    //friend
    friend Polynomial operator+ (const Polynomial&, const Polynomial&);
    friend Polynomial operator- (const Polynomial&, const Polynomial&);
    friend ostream& operator << (ostream&, const Polynomial&);
    friend istream& operator >> (istream&, Polynomial&);
	

    //CONSTANT MEMBER FUNCTIONS
    int getc1(void) const;
    int getc2(void) const;
    int getc3(void) const;
    int geterror(void) const;
    bool getwasset(void) const;
    std::string getpoly(void) const;
    

    // MODIFICATION MEMBER FUNCTIONS
    void setc1(const int);
    void setc2(const int);
    void setc3(const int);
    void seterror (const int);
    void setwasset (const bool);
    void setpoly(void);
    void display(void) const;

  private:
  	int c1, c2, c3;
  	int error;
  	bool wasset;
  	std::string poly;
};


#endif