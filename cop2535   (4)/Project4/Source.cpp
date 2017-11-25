//Rebecca Flake
//COP2535.CM1
//This program will use a single stack to check if a string read in from a file has balanced parentheses 

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isOpen(char c);						//Prototype for the function that checks if the character is an opening parentheses
bool isClose(char c);						//Prototype for the function that checks if the character is a closing parentheses
bool isMatching(char c1, char c2);			//Prototype for the function that checks if the characters match
bool CheckBalance(string input);			//Prototype for the balance checking function 

int main()
{
	ifstream inputFile;						//File object
	string input;							//Variable that holds the string to be checked

	cout << " Balance Checker\n\n";

	//Open File	
	inputFile.open("inputString.txt");
		//Handle errors
	if (inputFile.fail())
		cout << " There was an error opening the file.\n";
	else
	{
		//Read the file into a sting
		getline(inputFile, input);
		//close the file 
		inputFile.close();
	}
	cout << " The input string is: \n" << input << endl << endl;

	//check for balance 
	if (CheckBalance(input))				//The function has returned true and the parentheses are balanced 
		cout << " The parentheses in the string are balanced\n\n";
	else                                    //The function has returned false and the parentheses are not balanced 
		cout << " The parentheses in the string are not balanced\n\n";

	return 0;

}


/******************************************************
*						isOpen						  *
* A function that accepts a character as an argument. *
* If the character is an opening parentheses it will  *
* return true, otherwise it will return false.        *
******************************************************/

bool isOpen(char c)
{
	if (c == '(' || c == '[' || c == '{')	//The character is an opening parentheses
		return true;
	else                                    //The character is not an opening parentheses
		return false;
}
/******************************************************	
*						isClose						  *
* A function that accepts a character as an argument. *
* If the character is a closing parentheses it will	  *
* return true, otherwise it will return false.		  *
******************************************************/
bool isClose(char c)
{
	if (c == ')' || c == ']' || c == '}')	//The character is a closing parentheses
		return true;
	else                                    //The character is not a closing parentheses
		return false;
}

/**********************************************************
*						isMatching						  *
* This function accepts two characters as arguments and   *
* checks if they are a matching set of parentheses. If    *
* the characters are a set it will return true, otherwise *
* it will return false.									  *
***********************************************************/
bool isMatching(char c1, char c2)
{
	if (c1 == '(' && c2 == ')')				//The two characters are a set of parentheses
			return true;
	if (c1 == '[' && c2 == ']')				//The two characters are a set of square braces
			return true;
	if (c1 == '{' && c2 == '}')				//The two characters are a set of curly braces
		return true;
	else                                    //The two characters are not a matching set
		return false;
}

/***************************************************************************************
*								   CheckBalance										   *
* This function checks the string to see if its parentheses are matched.			   *
* It accepts the input string as an argument and then creates a character stack.	   *
* The string is stepped through by a for loop that uses two functions to determine     *
* if each character is an opening or closing parentheses. If the character is an       *
* opening parentheses it is pushed onto the stack. If the character is a closing	   *
* parentheses a function is called that compares the closing parentheses to the		   *
* opening parentheses in the top position of the stack. If the characters match the	   *
* opening parentheses is popped off the stack and the sequence repeats.                *
* The function will return true or false to the main function depending on the result. *
***************************************************************************************/
bool CheckBalance(string input)
{
	int n = input.length();												//Variable that holds the length of the string
	stack< char, vector<char>> iStack;								    //Stack for the opening parentheses
	//loop that steps through the string
	for (int i = 0; i < n; i++)
	{	
		char test = input[i];											//Variable to hold the current character
		//The input is an opening parentheses
		if (isOpen(test))
			//push the parentheses onto the stack
			iStack.push(test);

		//The input is a closing parentheses
		if (isClose(test))
		{	//The stack is empty, or the set fails the matching test
			if (iStack.empty() || !isMatching(iStack.top(), test))		//is Matching compares the character at the top of the stack with the current character.
				return false;
			//The stack is not empty and the characters are matching
			else
				iStack.pop();
		}
	}
	//The stack is empty, but there is a hanging closing parentheses
	if (!iStack.empty())	
		return false;
	//The stack is empty and there are no hanging parentheses of any kind
	else                    
		return true;
}	
