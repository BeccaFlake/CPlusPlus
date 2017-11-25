//Rebecca Flake
//COP2535.CM1
/*This program will read the contents of a file into two identical arrays. 
One array will be sorted in ascending  order with a bubble sort and the other 
will be sorted in descending order with a selection sort. The number of exchanges in
each sort will then be displayed on the screen. The value of 869 will be searched for 
in each array, first with a liner search and then with a binary search. The number of
comparisons carried out in each will be displayed in the console. */


#include<iostream>
#include<fstream>
//Include the header file to work with files
using namespace std;

//Function prototypes go here

void bubble_sort(int array1[], const int SIZE);											//Prototype for the bubble sort function  
void selection_sort(int array2[], int arrayCopy[], const int SIZE);						//Prototype for the selection sort function 
void linear_search(const int array2[], const int SIZE, const int VALUE);				//Prototype for the linear search function 
void binary_search(const int array1[], const int SIZE, const int VALUE);				//Prototype for the binary search function 

int main()
{	
	//Variable definitions
	ifstream inputFile;			
	const int SIZE = 200;		//Constant variable to hold the size for the arrays
	const int VALUE = 869;		//Constant variable to hold the value being searched for
	int array1[SIZE];			//The first array to hold the values read in from the file
	int array2[SIZE];			//The second array to hold the values read in from the file
	int arrayCopy[SIZE];		//An empty array that will have the contents of array2 copied into it to be sorted, keeping the original array2 contents random for the linear sort

	//Print basic information
	cout << " Sorting and Searching Algorithm Comparisons\n\n\n";

		//Import the file 
	inputFile.open("random.txt");
		//Handle exception
	if (!inputFile)
		cout << "Error opening file" << endl;
		//Read file data into the two arrays
	else
	{
		int count = 0;
		while (count < SIZE && inputFile >> array1[count])
		{
			array2[count] = array1[count];
			count++;
		}
	}
		//Close the file
	inputFile.close();


	//Call to the bubble sort function
		bubble_sort(array1, SIZE);

	//Call to the selection sort function
		selection_sort(array2, arrayCopy, SIZE);

	//Call to the liner sort function
		linear_search(array2, SIZE, VALUE);

	//Call to the binary search function
		binary_search(array1, SIZE, VALUE);

		cout << endl << endl;
	return 0;
}

/********************************************************************************************************************************************************/

			/***************************
			*						   *
			*	Function definitions   *
			*                          *
			***************************/


/******************************************************
*			        bubble_sort						  *
*													  *
* Uses a bubble sort algorithm to sort the contents   *
* of an array in ascending  order .It also counts the *
* number of exchanges made and then displays this     *
* in the console.								      *
******************************************************/

void bubble_sort(int array1[], const int SIZE)
{
	//Sort the array in ascending  order with a bubble sort algorithm 
	int temp,													//Variable that temporarily holds the first value to be swapped
	    bubbleCount = 0;										//Counter for the number of exchanges made by the sort
	bool madeAswap;												//Flag variable that controls the search

	do
	{
		madeAswap = false;									   //Flag variable initialized to false
			//Sort the array while the count is less than the size of the array
			for (int count = 0; count < (SIZE - 1); count++)  	
		{
			//Make a swap is the value in the current index is greater than the value in the next index.
			if (array1[count] > array1[count + 1])
			{
				temp = array1[count];
				array1[count] = array1[count + 1];
				array1[count + 1] = temp;
				madeAswap = true;
				bubbleCount += 1;
			}
		} 
	}while (madeAswap);											//Check the flag variable to see if the loop needs to repeat

	//display the count
	cout << " The bubble sort made " << bubbleCount << " exchanges to sort the array in ascending  order.\n";
}

/***************************************************************
*					  selection_sort						   *
*															   *	
* First copies the accepted array. The copy of the array	   *
* is then sorted with a selection sort algorithm in descending *
* order. It also counts the number of exchanges made and       *
* then displays this in the console.						   *
***************************************************************/

void selection_sort(int array2[], int arrayCopy[], const int SIZE)
{
	//make a copy of array2 to be sorted, preserving the original array to be used in the linear sort
	for (int index = 0; index < SIZE; index++)
	{
		arrayCopy[index] = array2[index];
	}
	 
	//selection sort algorithm, descending order. 
	int startScan,												//Variable to hold the index where the scan begins
		maxIndex,												//Variable to hold the index of the last value in the array
		maxValue,											    //Variable to hold the index of the maximum value in the array
	    selectionCount = 0;										//A counter to keep track of the number of exchanges made by the sort
	//Sort the array while the value held in start scan is less than the number of memory locations in the array
	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		maxIndex = startScan;									//Set the maximum index to the value held in start scan
		maxValue = arrayCopy[startScan];						//Set the maximum value to the first value in the array
		//Make swaps while the index is less than the number of memory locations in the array
		for (int index = startScan + 1; index < SIZE; index++)	
		{
			//If the value in the current index is greater than the value in maxvalue than a swap should be made.
			if (arrayCopy[index] > maxValue)
			{
				maxValue = arrayCopy[index];
				maxIndex = index;
			}
		}
		arrayCopy[maxIndex] = arrayCopy[startScan];
		arrayCopy[startScan] = maxValue;
		selectionCount++;
	}

//display the count
	cout << " The selection sort made " << selectionCount << " exchanges to sort the array in descending order.\n\n";
}


/***************************************************************
*					     linear_search						   *
*															   *
* Searches the accepted array for a given value by using a	   *
* linear search algorithm. It counts the number of comparisons *
* made and displays this in the console.					   *
***************************************************************/

void linear_search(const int array2[], const int SIZE, const int VALUE)
{
	int index = 0,												//Variable to hold the index being searched
		linearCount = 0,										//A counter for the number of Comparisons made by the search
		position = -1;											//Variable that holds the position of the found value
	bool found = false;

	//Search for the value with a linear search algorithm 
	//If found has not been set to 'true' the while loop repeats
	while (index < SIZE && !found)
	{	
		if (array2[index] == VALUE)								//The value is at the index and the search was successful
		{
		 found = true;
		 position = index; 
		}
		index++;
		linearCount++;
		
	}

	//Display the count
	cout << " The linear search made " << linearCount << " comparisons before the value " << VALUE << " was found.\n";
}
	
/***************************************************************
*						 binary_search						   *
*															   *
* Searches the accepted array for a given value by using a	   *
* binary search algorithm. It counts the number of comparisons *
* made and displays this in the console.				       *
***************************************************************/
void binary_search(const int array1[], const int SIZE, const int VALUE)
{
//Search for the value with a binary search algorithm 
	int first = 0,												//Variable that holds the first value in the search range
		last = SIZE - 1,										//Variable that holds the last value in the serach range
		middle,													//Variable to hold the middle value in the search range
		position = -1,											//The index that is being searched
		binaryCount = 0;										//A counter for the number of comparisons made during the search
	bool found = false;											//Flag variable that controls the search

	//Search for the value while the Boolean value is false, and the first value is less than or equal to the last. 
	while (!found && first <= last)
	{
		middle = ((first + last) / 2);							//Middle is the average 
		if (array1[middle] == VALUE)							//The value is at the searched index
		{
			found = true;
			position = middle;
		}
		else if (array1[middle] > VALUE)						//The value is in the lower half 
		{
			last = middle - 1;
		}
		else													//The value is in the upper half 
		{
			first = middle + 1;
		}
		binaryCount++;
	}

	//Display the count
	cout << " The binary search made " << binaryCount << " comparisons before the value " << VALUE << " was found.\n";
}

