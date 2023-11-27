#include <iostream>
#include "poly.h"
#include <fstream>
#include <string>

Polynomial::Polynomial() // constructor
{
	c1 = 0;			//sets all data to 0, blank, or false
	c2 = 0;
	c3 = 0;
	error = 0;
	poly = "";
	wasset = false;
}
int Polynomial::getc1(void) const
{
	return c1; 			//returns c1
}

int Polynomial::getc2(void) const
{
	return c2;			//returns c2
}

int Polynomial::getc3(void) const
{
	return c3;			//returns c3
}

int Polynomial::geterror(void) const
{
	return error;		//returns error
}

bool Polynomial::getwasset(void) const
{
	return wasset;		//returns wasset
}

string Polynomial::getpoly(void) const
{
	return poly;		//returns poly string
}

void Polynomial::setc1(const int temp)
{
		c1 = temp;		//sets c1 to value of temp
}

void Polynomial::setc2(const int temp)
{
	
		c2 = temp;		//sets c2 to value of temp
}

void Polynomial::setc3(const int temp)
{

		c3 = temp;		//sets c3 to value of temp
}

void Polynomial::setwasset(const bool temp)
{
	if (temp == true || temp == false)
	{
		wasset = temp;		//sets value of wasset to temp if value is true or false
	}
}

string getsign(int s)
{
	string sign = "";	//sets a temporary string named sign to blank
	if (s >= 0)
	{
		sign = "+";		//sets sign to + if number is greater than 0 (negative numbers have the - already)
	}
	
	return sign;		//returns string sign
}

void Polynomial::setpoly(void)
{
	if (geterror() == 0)	//makes sure no errors were detected before combining string
	{
		int x2 = getc1();	//gets c1 value
		int x = getc2();	//gets c2 value
		int y = getc3();	//gets c3 value
		poly = to_string(x2) + "x^2" + getsign(x) + to_string(x) + "x" + getsign(y) + to_string(y);		//builds combined string that turns into polynomial
	}
}

void Polynomial::seterror(const int temp)
{
	if (temp == 0 || temp ==1)
	{
		error = temp;		//sets error to temp if temp is 0 or 1
	}
}

void Polynomial::display(void) const
{
	cout << "This polynomial contains " << c1 << " " << c2 << " " << c3 << " " << error << " " << wasset << " " << poly; //displays all data of polynomial
}

//Overloaded operators
Polynomial operator + (const Polynomial& p1, const Polynomial& p2)
{
	Polynomial temp;	//creates temporary polynomial object
	
	temp.c1 = p1.c1 + p2.c1;			//adds all integer data of polynomial on the left to the polynomial on the right
	temp.c2 = p1.c2 + p2.c2;			//and stores it into temps integer values
	temp.c3 = p1.c3 + p2.c3;
	
	return temp;	//returns temp object
}

Polynomial operator - (const Polynomial& p1, const Polynomial& p2)
{
	Polynomial temp;	//creates temporary polynomial object
	
	temp.c1 = p1.c1 - p2.c1;	//subtracts all integer data of polynomial on the left to the polynomial on the right
	temp.c2 = p1.c2 - p2.c2;	//and stores it into temps integer values
	temp.c3 = p1.c3 - p2.c3;
	
	return temp;		//returns temp object
}
ostream &operator << (ostream &outp, const Polynomial &p1)
{
	
	outp << p1.getpoly() << endl;		//prints out poly created in setpoly()
	return outp;						//returns outp
}

int getnum(string p)	
{
	int temp = 0;	//sets temporary int to 0
	if (p.find_first_not_of("+-0123456789")) //checks to make sure only numbers and a + or - sign is present
	{
			temp = stoi(p.c_str());		//converts string to int and stores in temp
	}
	
	return temp;
}

istream &operator >> (istream &inp, Polynomial &p1)
{
	string temp;		//creates temporary string
	getline(inp, temp);		//gets line user entered input from and places into temp
	
	int num = temp.find("x^2");		//checks for x^2 string within temp and stores index in value num
	if (num == -1 || temp.find(" ") != -1)	//checks to make sure the string was found and no spaces were found
	{
		p1.seterror(1);		//sets error to 1 if found
	}
	else
	{
		string s1 = temp.substr(0, num);		//breaks temp into substring starting from index 0 to index num
		p1.setc1(getnum(s1));;					//sets our first integer value using the s1 substring
		string s2 = temp.substr(num+3, temp.length());	//sets second substring using remaining index
		int x = s2.find("x");					//stores index of char x into int x
		if (s2.find("x") == -1)
		{
			p1.seterror(1);		//sets error to 1 if x not found
		}	
		string s3 = s2.substr(0, x);					//creats s3 using 0 index of s2 and index x
		p1.setc2(getnum(s3));							//stores our second integer value using s3 substring
		string s4 = s2.substr(x+1, s2.length());		//creates s4 using remaining index of s2
		p1.setc3(getnum(s4));							//stores third and final variable using s4
		p1.setpoly();										//sets our poly string
		p1.setwasset(true);								//sets wasset to true, indicating a polynomial was entered
	}
	
	
	return inp;		//returns inp
}	


