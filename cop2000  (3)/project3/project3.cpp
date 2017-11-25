//Rebecca Flake
//COP2000.0M3
//This program will calculate Body mass index (BMI) based on user input. It will then display the results and the range that the BMI falls within.

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//program code goes here
	//Define the variables
	double height,
		   weight,
		   bmi;
	string range;

	//Ask for input and store it in the height and weight variables. 
	cout << "BMI Calculator\n\n";
	cout << "Please use numeric values for the input.\n";
	cout << "What is the height in inches?: ";					//Ask for height in inches	
	cin >> height;
	cout << "What is the weight in pounds?: ";					//Ask for weight in pounds	
	cin >> weight;

	//Validate the input
	if ((height > 0) && (weight > 0))
	{															//The input was valid and the program will proceed
		bmi = ((weight * 703)/(pow(height, 2)));				//BMI formula is (BMI = weight*703/height^2) and needs pow function														
		if ((bmi >= 18.5) && (bmi <= 25))						//Determine the range
			range = "optimal";
		else if (bmi < 18.5)
			range = "underweight";
		else
			range = "overweight";

		//Display the BMI and the range result
		cout << fixed << setprecision(1);
		cout << "\nYour BMI is " << bmi << " and it falls within the " << "\"" << range << "\"" << " range.\n\n";

	}
	//If the input was not valid
	else														
	{
		cout << "\nPlease try again. Enter the height and weight as numeric values greater than zero." << endl;
	}

	return 0;

}
