//Rebecca Flake
//COP2000.0M3
/* The program will make use of a class. The user will be prompted for a circle's radius 
and this will create a class object. Then the program will report the circle's area, diameter, 
and circumference with 2 decimal places. */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Circle
{
/**************************
 * circle class variables *
 * and methods            *
 **************************/
private:
	float radius,
		 area,
		 diameter,
		 circumference,
		 pi = 3.14159;
	void setRadius(float);									//sets the radius value

public:
	Circle();												
	float getRadius(float radius, float pi);				//an accessor function for the radius variable
	float getArea(float radius, float pi);					//returns the area of a circle, which is calculated as
	float getDiameter(float radius);						//returns the diameter of a circle
	float getCircumference(float radius, float pi);			//returns the circumference of the circle
};

int main()
{
	Circle circle1;											//instantiate an object from the class
	float radius = 0,
		  area,
		  diameter,
		  circumference,
		  pi = 3.14159;

//program code goes here

	//Get the input and validate it
	radius = circle1.getRadius(radius, pi);

	//get area
	diameter = circle1.getDiameter(radius);

	//get diameter 
	area = circle1.getArea(radius, pi);

	//get circumference
	circumference = circle1.getCircumference(radius, pi);

	//print the results
	cout << endl;
	cout << "Radius: " << fixed << showpoint << setprecision(2) << radius << endl << "Diameter: " << diameter << endl
		 << "Circumference: " << circumference << endl << endl;

	return 0;
}

/********************************
* circle class member functions *
*********************************/

/***************************
*		constructor        *
*  sets radius value = 0.0 *
****************************/
Circle::Circle()
{
	radius = 0.0;
}

/********************************************
*   			setRadius  					*	
*  mutator function for the radius variable *
*********************************************/
void Circle::setRadius(float r)
{
	if (r >= 0.0)
		radius = r;
}

/********************************************
*			     getRadius  				*
* accessor function for the radius variable *
*********************************************/
float Circle::getRadius(float radius, float pi)
{
	cout << "Please enter the radius of the circle as a numerical value: ";
	cin >> radius;
	//validate the input
	while ((!cin) || (radius <= 0))    //did not read the value
	{
		cin.clear();				   //revert the read bits back to a good read
		cin.sync();				       //clear the buffer
		cin.ignore(100, '\n');
		cout << "Enter a numerical value greater than zero. Try again: ";
		cin >> radius;
	}
	return radius;
}

/*********************************
*			getArea  			 *	
* returns the area of the circle *
**********************************/

float Circle::getArea(float radius, float pi)
{
	return pi * pow(radius, 2);
}
/*********************************
*		   getDiameter  		 *
* returns diameter of the circle *
**********************************/

float Circle::getDiameter(float radius)
{
	return 2 * radius;
}

/****************************
*	  getCircumference      *
* returns the circumference *
*****************************/ 
float Circle::getCircumference(float radius, float pi)
{
	return 2 * pi * radius;
}