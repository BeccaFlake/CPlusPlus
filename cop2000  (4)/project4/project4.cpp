//Rebecca Flake
//COP2000.0M3
/*This program will read numbers from a file. It will keep a count and a running total of the numbers as it reads through the file.
Once the file has been read the program will calculate the average of the numbers. Finally, all three of the values will be displayed in the console.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
//program code goes here
	//Input the file, define variables, and open the file
	ifstream inputFile;
	int count= 0,
		number;
	double 	total = 0.0,
		    average;

	inputFile.open("Random.txt");
	
	//End the program if the file fails to open.
	if (!inputFile)
	{
		cout << "The file failed to open." << endl;
		return 1;
	}

	//Read the file
	while (inputFile >> number)
	{
		count++;					//Counts the number of values
		total += number;			//Keeps a running total of the values
	}

	//Calculate the average
	average = (total / count);

	//Display the values
	cout << "\nThere are " << count <<" numbers in the file." << endl;
	cout << "The sum of these numbers is " << total <<"." << endl;
	cout << "The average of the numbers in the file is " << average << "." << endl << endl;

	//Close the file before ending the program
	inputFile.close();
	return 0;

}