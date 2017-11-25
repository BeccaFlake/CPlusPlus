//Rebecca Flake
//COP2000.0M3
//This program will play a simple word game with the user to make a short story. 

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//program code goes here

	string name, age, city, college, profession, animal, pet_name;   //define variables

	//Greet the user and explain the game
	cout << "\nWelcome to the game, enter the required information when prompted.\n\n";

		//Ask the user to enter the information
	
		cout << "Please enter your name: ";					//Get name
		getline(cin, name);
	
		cout << "Please enter your age: ";					//Get age
		getline(cin, age );
	
		cout << "Please enter the name of a city: ";		//Get name of a city
		getline(cin, city);

		cout << "Please enter the name of a college: ";		//Get a college
		getline(cin, college);

		cout << "Please enter a profession: ";				//Get a profession
		getline(cin, profession);

		cout << "Please enter a type of animal: ";			//Get a type of animal
		getline(cin, animal);

		cout << "Please enter a pet's name: ";				//Get a pet's name
		getline(cin, pet_name);

		cout << "\n\n\n";

	//Combine the input into a story
	
	cout << "There once was a person named " << name << " who lived in " << city << ".\n";
	cout << "At the age of " << age  << ", " << name << " went to college at " <<college <<".\n";
	cout << name << " graduated and went to work as a " << profession <<".\n";
	cout << "Then, " << name << " adopted a(n) " << animal << " named " << pet_name << ".\n";
	cout << "They both lived happily ever after!\n\n";

	cout << "Thank you for playing!\n";
	return 0;

}