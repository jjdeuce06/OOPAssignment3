#include <iostream>
#include "poly.h"
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

int main(void) {
	
	int decision = 0;		//creates int decision with value of 0
	Polynomial p1;			//creats p1 and p2 objects, as well as an answer polynomial
	Polynomial p2;
	Polynomial answer;
	
	cout << "Welcome to the polynomial calculator!" << endl;			//welcome menu printed for the user
	cout << "Here's the options" << endl;
	cout << "1. Enter Polynomial 1" << endl;
	cout << "2. Enter Polynomial 2" << endl;
	cout << "3. Add the polynomials" << endl;
	cout << "4. Subtract the polynomials" << endl;
	cout << "5. End program" << endl;
	
	
while(true)		//while loop beginning
{
	
	cout << "Select an option: ";		//asks user to input a number from the menu
	while((!(cin >> decision) || cin.peek() != '\n'))
   {
     cout << "Please enter an INTEGER: ";			//ensures an integer is entered in the menu
     cin.clear();
     cin.ignore(30000, '\n');            
   }
   
   switch(decision)		//switch beginning
   {
   	case 1:
   		cin.clear();		//flushing input stream to make sure it doesn't read decision input
		fflush(stdin);
		p1.seterror(0);		//resets error to 0
   		cout << "Enter a polynomial: " << endl;		//asks for polynomial
   		cin >> p1;									//calls overloaded cin operator for p1
   		if (p1.geterror() == 1)
   		{
   			cout << "This has been flagged for an error" << endl;		//printed if an error was found in the input
		}
		else
		{
			cout << p1;		//prints out polynomial
		}
		break;
	case 2:
		cin.clear();			//flushing input stream to make sure it doesn't read decision input
		fflush(stdin);
		p2.seterror(0);			//resets error to 0
		cout << "Enter a polynomial: ";		//asks for polynomial
   		cin >> p2;							//calls overloaded cin operator for p1
   		if (p2.geterror() == 1)
   		{
   			cout << "This has been flagged for an error" << endl;		//printed if an error was found in the input
		}
		else
		{
			cout << p2;		//prints out polynomial
		}
		break;
	case 3:
		if(p1.geterror() == 1 || p2.geterror() == 1)
		{
			cout << "One of the polynomials was declared to have an error" << endl;		//prints if an error is found in p1 or p2
		}
		else if(p1.getwasset() == false || p2.getwasset() == false)
		{
			cout << "You have not entered two polynomials" << endl;			//prints if wasset is false, indicating nothing was entered for p1 or p2
		}
		else
		{
			answer = p1 + p2;			//uses overloaded + operator to add p1 and p2
			answer.setpoly();			//sets poly string for our answer
			cout << answer;				//prints out answer
		}
		break;
	case 4:
		if(p1.geterror() == 1 || p2.geterror() == 1)
		{
			cout << "One of the polynomials was declared to have an error" << endl;		//prints if an error is found in p1 or p2
		}
		else if(p1.getwasset() == false || p2.getwasset() == false)
		{
			cout << "A polynomial is missing" << endl;						//prints if wasset is false, indicating nothing was entered for p1 or p2
		}
		else
		{
			answer = p1 - p2;		//uses overloaded - operator to add p1 and p2
			answer.setpoly();		//sets poly string for our answer
			cout << answer;			//prints out answer
		}
		break;
	case 5:
		cout << "Goodbye!" << endl;		//exiting message
		break;
	default:
		cout << "This is not a valid choice, try again" << endl;		//message for any value entered not 1-5
		break;
   }
   
   if (decision == 5)
   {
   		break;		//breaks the loop when 5 is entered
   }
   
}
	
	return 0;
}