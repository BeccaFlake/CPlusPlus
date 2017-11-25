//Rebecca Flake
//COP2000.0M3
//This program will calculate the area of a rectangle based on user input. It will then display the input and the result in the console. 

#include <iostream>
using namespace std;

//prototypes for the functions
void welcome();
float getLength(float& input);								
float getWidth(float& input);							    
void validate(float&);
float getArea(float length, float width);
void displayData(float length, float width, float area);


int main()
{
//program code goes here
	//define the local variables   
	float input,			//the values entered by the users
		  length,			//the length of the rectangle
		  width,			//the width of the rectangle
		  area;				//the calculated area of the rectangle

	//welcome function
	welcome();

	//get the length and return it to the length variable
	length = getLength(input);

	//get the width and return it to the width variable
	width = getWidth(input);

	//calculate the area based on the validated input
	area = getArea(length, width);

	//display the results
	displayData(length, width, area);

	return 0;
}

//**********************//
//*function definitions*//
//**********************//

/*************************************
 *             Welcome               *
 * this function prints instructions *
 *          to the console           *
 *************************************/
void welcome()
{
	cout << "Area Calculator\n\n"
		 << "Input information as numerical values at the prompts and then press 'ENTER'\n\n" ;
}


/***************************************
 *             getLength               *
 * this function gets the length input *
 * from the user as an argument and    *
 * returns it if it is valid           *
 ***************************************/
float getLength(float& input)
{	
	cout << "Enter the length of the rectangle: ";
	cin >> input;
	
	//validate the input
	validate(input);

	return input;
}
/***************************************
 *              getWidth               *
 * this function gets the width input  *
 * from the user as an argument and    *
 * returns it if it is valid           *
 ***************************************/
float getWidth(float& input)
{
	cout << "Enter the width of the rectangle: ";
	cin >> input;

	//validate the input
	validate(input);

	return input;
}

/***************************************
 *             validate                *
 * this function takes the input and   *
 * checks that it is a numeric value   *
 * and is greater than zero. It loops  *
 * until the user enters valid input   *
 ***************************************/
void validate(float& in)
{
	while ((!cin) || (in <= 0))    //did not read the value
	{
		cin.clear();			   //revert the read bits back to a good read
		cin.sync();				   //clear the buffer
		cin.ignore(100, '\n');
		cout << "Enter a numerical value greater than zero. Try again: ";
		cin >> in;
	}
}

/*****************************************
 *             getArea                   *
 * this function accepts the length and  *
 * width variables as arguments. Then    *
 * multiplies these values and assigns   *
 * the result to the area variable.      *
 * The area is returned.                 *
 *****************************************/
float getArea(float length, float width)
{
	float area = (length * width);
	return area;

}

/*******************************************
*             displayData                  *
* this function accepts the length,        *
* width, and area as arguments. Then       *
* these values are printed to the console  *
* imbedded in an explanatory message       *
********************************************/
void displayData(float length, float width, float area)
{
	cout << "\nA rectangle with a length of " << length << " and a width of "
		<< width << " has an area of " << area << "." << endl << endl;
}