//Rebecca Flake
//COP2000.0M3
/*This program will read in a string from the user and then let the user know what string positions are available to view. 
If the user enters a value that is not within the string boundaries, the program should throw an exception.
If the user enters a legal value, the character at that string position will be printed to the console.*/


#include "header.h"															//Include the class header file
#include <iostream>
using namespace std;

string getString(string s);													//Prototype for the getString function. Returns a string.
int getPosition(int k, string s);											//Prototype for the getPosition function. Returns an integer.
void checkBounds(int k, string s, BCheckString string1, char character);	//Prototype for the checkBoounds function. A void function.

int main()
{	//Variables
	string s;						//String variable to hold the input string
	int k = 0;						//Integer variable to hold the input position 
	char character = ' ';			//Character variable to hold the returned character at the position
	char choice = 'y';				//Loop control character variable
	
	//Code body
	cout << " This program demonstrates bounds checking on string objects.\n\n";
		//Get user input for the string with the getString function
		s = getString(s);
		//Use the input to create an instance of the BCheckString class
		BCheckString string1(s);

		//A loop that lets the user check as many positions as they would like
		while (choice == 'y')
		{	//Get the position and bounds check it with the checkBounds function
			checkBounds(k, s, string1, character);
			//Ask the user if they would like to try again
			cout << "\n Would you like to try another position? (y/n) ";
			cin >> choice;
			cin.ignore();			//Clear the buffer
		}
	 return 0;
}


				 /*****************************
			     *    Function Definitions	  *
			     ******************************/


/**************************************************************
*						   getString						  *	
*  A function that accepts the s variable as an argument and  *
*  asks the user for a string. The string is then returned	  *
**************************************************************/
string getString(string s)
{	//Get the string from the user
	cout << " Please enter a string: ";
	getline(cin, s);
	cout << endl;
	return s;
}

/*******************************************************************
*					      getPosition						       *
*   A function that accepts the k variable as an argument and      *
*   asks the user for an integer. The input is validated and then  *
*   the integer is returned in the k variable.					   *			
*******************************************************************/

int getPosition(int k, string s)
{	//Inform the user of the legal string positions
	cout << "\n Available string positions are: " << 0 << "-" << (s.length()-1) << endl << endl;
	//Get the position from the user
	cout << " Please enter an integer describing a position: ";
	cin >> k;
	cin.ignore();					//clear the buffer
	//Validate the input as an integer
	while (!cin)
	{
		cin.clear();			   //revert the read bits back to a good read
		cin.sync();				   //clear the buffer
		cin.ignore();

		cout << " Enter an integer value. Try again: ";
		cin >> k;
		cin.ignore();			   //clear the buffer
	}
	return k;
}

/********************************************************************
*					      checkBounds						        *
*  This function accepts the k, s, and character variables as		*
*  arguments, as well as the string object. It first calls the		*
*  getPosition function	and then uses a try/catch construct			*
*  to handle any exceptions	thrown by the operator function, which  *
*  checks that the user entered position is within the bounds of    *
*  the string. If the operator function successfully locates the    *
*  character at the position, the character is printed to the       *
*  console. Otherwise, the catch block will print an error message. *
********************************************************************/
void checkBounds(int k, string s, BCheckString string1, char character)
{
	k = getPosition(k, s);
	//Bounds checking and exception handling
	try
	{	//Bounds check using the operator member function of the BCheckString class, return the character if possible
		character = string1[k];
		//Print the character at the location to the console
		cout << "\n The character at position " << k << " is '" << character << "'.\n";
	}
	//Catch the exception thrown by the operator member function of the BCheckString class
	catch (BCheckString::BoundsException)			
	{	//Print the error message
		cout << "\n Access violation in string.\n";	
	}
}
	