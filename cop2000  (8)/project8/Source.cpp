//Rebecca Flake
//COP2000.0M3
/*This program will track snow depth over the course of a week. The user will input data, 
which will be stored in two arrays. The arrays are then combined into a single 2d array.
This combined array is sorted in ascending order by depth and printed to the screen*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Class Goes Here
class SnowReport
{
private:
	const int SIZE = 7;
	const int ROWS = 2;
	const int COLUMNS =7;
	int startDate;
	int endDate;
	int dateArray;
	double depthArray;
	double comboArray;
	string month;

public:
	SnowReport();
	void getPeriod(string& month, int& startDate, int& endDate);
	void getData(string month, int startDate, int endDate, int dateArray[], double depthArray[], double comboArray[][2], const int SIZE, const int COLUMNS, const int ROWS);
	double sortArray(double comboArray[][2], const int COLUMNS, const int ROWS);
	void display(string month, int startDate, int endDate, double comboArray[][2], int COLUMNS, const int ROWS);
};

int main()
{
	SnowReport snowreport1;
	const int SIZE = 7;
	const int ROWS = 7;
	const int COLUMNS = 2;
	int startDate;
	int endDate;
	int dateArray[SIZE];
	double depth = 0.0;
	double depthArray[SIZE];
	double comboArray[ROWS][COLUMNS];
	string month;
	cout << " Snow Condition Log\n\n";
	//get period
	snowreport1.getPeriod(month, startDate, endDate);
	//get data
	snowreport1.getData(month, startDate, endDate, dateArray, depthArray, comboArray, SIZE, COLUMNS, ROWS);
	//display
	snowreport1.display(month, startDate, endDate, comboArray, COLUMNS, ROWS);
}

//Functions go here


/************************
*	   Constructor  	*
*************************/

SnowReport::SnowReport() 
{
	const int SIZE = 7;
	const int ROWS = 7;
	const int COLUMNS = 2;
	int dateArray[SIZE] = {};
	double depthArray[SIZE] = {};
	double comboArray[ROWS] = {};
}


/****************************************************
*                     getPeriod					    *
*	A void function that accepts the month,			*
*   startDate and endDate variables as arguments.	*
*	It receives user input to get the name of the 	*
*	month, the start date, and end date for the 	*
*	report. Input is validated before proceeding.   *
*****************************************************/
void SnowReport::getPeriod(string& month, int& startDate, int& endDate)
{
	//get the month
	cout << " Please enter the name of the month: ";
	cin >> month;
	//get the starting date
	cout << " Please enter the START date for the report as an integer: ";
	cin >> startDate;
		while ((!cin) || (startDate <= 0) || (startDate > 31))
		{
			cin.clear();			   //revert the read bits back to a good read
			cin.sync();				   //clear the buffer
			cin.ignore(100, '\n');
			cout << " Enter a value in the range of 1 - 31. Try again: ";
			cin >> startDate;
		}

	//get the ending date
		cout << " Please enter the END date for the report as an integer: ";
		cin >> endDate;
	    if (endDate < (startDate + 6))
		{
			cin.clear();			   //revert the read bits back to a good read
			cin.sync();				   //clear the buffer
			cin.ignore(100, '\n');
			cout << " That period is too short. Try again: ";
			cin >> endDate;
		}
		if (endDate > (startDate + 6))
		{
			cin.clear();			   //revert the read bits back to a good read
			cin.sync();				   //clear the buffer
			cin.ignore(100, '\n');
			cout << " That period is too long. Try again: ";
			cin >> endDate;
		}
	cout << " The date range for the report is: " << startDate << "-" << endDate << endl <<endl;
}

/**************************************************************************
*								setData									  *
*  A void function that accepts the, month, startDate, and endDate        *
*  variables; the dateArray, depthArray, and comboArray; and the size,    *
*  columns, and rows constants as arguments.							  *
*  It then uses a while loop to validate and assign the date input to	  *
*  the dateArray and the depthArray. A set of nested for loops creates    * 
*  a 2D array from the arrays holding the dates and depths. The sortArray *
*  function is called to sort the 2D array in ascending order by depth.	  *
***************************************************************************/
void SnowReport::getData(string month, int startDate, int endDate, int dateArray[], double depthArray[], double comboArray[][2], const int SIZE, const int COLUMNS, const int ROWS)
{
	int count = 0;
	int date;
	double depth;
	
	//while loop that repeats until the arrays are full
	while (count < SIZE)
	{
		//fill the date array
		date = (startDate + count);
		dateArray[count] = date;

		//get the depth for the report
		cout << " For " << month << " " << date << ", enter the DEPTH of the snow in inches as a decimal value: ";
		cin >> depth;

		while ((!cin) || (depth < 0))
		{
			cin.clear();			   //revert the read bits back to a good read
			cin.sync();				   //clear the buffer
			cin.ignore(100, '\n');
			cout << "Enter a decimal value greater than or equal to zero. Try again: ";
			cin >> endDate;
		}
		cout <<" Entry Added."<< endl<< endl;	
		depthArray[count] = depth;
		count++;
	}

	// combine the arrays into one 2D array 
	for (int day = 0; day < ROWS; day++)
	{
		comboArray[day][0] = dateArray[day];
		for(int inches = 0; inches < ROWS; inches++)
		{ 
			comboArray[inches][1] = depthArray[inches];
		}
	}	
	//sort the array with the sortArray function
	sortArray(comboArray, COLUMNS, ROWS);
}
/*****************************************************************
*						   sortArray							 *
*   A double return type function that accepts the comboArray,	 * 
*	column constant, and rows constant as arguments.			 *
*	A selection sort algorithm is used to sort the 2D array	     *
*   in ascending order by depth. The sorted array is returned    *
*	to the getData function										 *
******************************************************************/
double SnowReport::sortArray(double comboArray[][2], const int COLUMNS, const int ROWS)
{
	int startScan, minIndex; 
	double minValue,
		minDate;
	//For startscan = 0 to the next-to-last array subscript
	for (startScan = 0; startScan < (ROWS - 1); startScan ++)
	{
		//set index to startscan
		//set minindex to startscan
		//set minvalue to array[startscan][1]
		//set minDate to array[startScan][0]
		minIndex = startScan;
		minValue = comboArray[startScan][1];
		minDate = comboArray[startScan][0];

		//for index = (startscan + 1) to the last subscript in the array
			for (int index = startScan + 1; index < ROWS; index++)
			{
			//if (array[index][1] < minvalue)
			    if (comboArray[index][1] < minValue)
				{
					//set minvalue and minDate to array[index]
					minValue = comboArray[index][1];
					minDate = comboArray[index][0];
					//set minindex to index
					minIndex = index;
				}
			}
			//set array[minindex] to array[startscan]
			comboArray[minIndex][1] = comboArray[startScan][1];
			comboArray[minIndex][0] = comboArray[startScan][0];
			//setarray[startscan] to minvalue
			comboArray[startScan][1] = minValue;
			comboArray[startScan][0] = minDate;
			
	}
	return comboArray[ROWS][COLUMNS];
}
/****************************************************************************
*							      display									*
*	void function that accepts the month, startDate, and endDate variables; *
*	the sorted comboArray; and the columns and rows constants as arguments. *
*	The function prints the basic information, the month, and date range.   *
*	A set of nested for loops is used to print each row of the 2D array.    *
*****************************************************************************/
void SnowReport::display(string month, int startDate, int endDate, double comboArray[][2], const int COLUMNS, const int ROWS)

{
	cout << "\n Snow Report	" << month << " " << startDate << "-" << endDate << endl;
	cout << right <<setw(19) << "  Date      Base\n";
	//nested loops that print the 2D array rows
	for (int day = 0; day < ROWS; day++)
	{
		for (int inches = 0; inches < COLUMNS; inches++)
		{
			cout << setw(9) << comboArray[day][inches];
		}
		cout << endl;
	}
}