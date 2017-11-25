//Rebecca Flake
//COP2535.CM1
/*The program will read 10 characters from a linked file into a linked list object. A copy of this list object will be made and the order of the contents reversed. 
Then the contents of both list objects will be displayed on the screen. The program uses the STL list container.*/ 

#include <iostream>
#include <fstream>
#include <list>
using namespace std;

void displayLists(list<char> charList1, list<char>charList2, list<char>::iterator iter);			//Prototype for the void function that displays the list contents

int main()
{	//Class Objects and iterator
	list<char> charList1;
	list<char> charList2;
	list<char>::iterator iter;
	//variable 
	char letter;

//Program body
	cout << " Linked List Creator\n\n";
	
	//Open the file
	ifstream charFile("linkedText.txt");
		//Handle possible errors
	if (!charFile)
	{
		cout << "There was an error opening the file.\n";
		exit(1);
	}
	//Read in the file
	while (charFile >> letter)
	{
		charList1.push_back(letter);
	}
	//Close File
	charFile.close();

	//Create the copy of the list
	charList2 = charList1;
	//Reverse the order of the nodes in the list copy
	charList2.reverse();

	//Display both lists
	displayLists(charList1, charList2, iter);

	return 0;
}
/***********/


void displayLists(list<char>charList1, list<char>charList2, list<char>::iterator iter)
{
	//Display the contents of the first linked list object
	cout << " The contents of the first linked list are: \n  ";
	for (iter = charList1.begin(); iter != charList1.end(); iter++)					//For loop that iterates though the list and prints the contents of each node
	{					
		cout << *iter << " ";
	}
	cout << endl << endl;

	//Display the contents of the second linked list object
	cout << " The contents of the second linked list are: \n  ";
	for (iter = charList2.begin(); iter != charList2.end(); iter++)					//For loop that iterates though the list and prints the contents of each node
	{				    
		cout << *iter << " ";
	}
	cout << endl << endl;

}