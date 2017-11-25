#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Class derived from the STL string class
class BCheckString : public string
{	
private:
	string str;		//new string object
	int size;		//size of the string
public:
	//BoundsException class declaration
	class BoundsException
	{};

	//Constructor that passes the string object to the base constructor
	class BCheckString(string s) : string(s)	//constructor
	{	size = s.length();						//Set the size variable to the length of the string
		str = new char[size];					//Make a character array to hold the string contents
		//Fill the array with the characters from the string
		for (int i = 0; i < size; i++)	
			str[i] = s[i];
	} 

	//Operator that performs the bounds checking
	 char operator[](int k)
	 {
		if (k < 0 || k >= size)				//An exception is thrown if the position 'k' is out of bounds
			throw BoundsException();		
		return str[k];						//The character at the position 'k' is returned if 'k' is within bounds
	}
};
#endif*/