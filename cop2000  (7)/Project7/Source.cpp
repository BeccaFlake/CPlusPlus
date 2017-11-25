//Rebecca Flake
//COP2000.0M3
/*This program will use a class to grade a test. The student's answers will be imported from a file so that they can be compared to the
answer key. The answer sets will be stored in arrays. The result, the correct/incorrect answer counts, and the numbers of 
any missed questions will be printed to the console.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TestGrader
{
	/******************************
	* Test Grader class variables *
	*         and methods         *
	******************************/
private:
	string studentAnswers,				//String variable that holds the student's answers after being read from the file
		verdict,					    //String variable that holds the message of whether or not the student passed the exam
		answers,						//String array to hold the answer key
		student,					    //String array to hold the student answers
		correctAnswers;					//String variable that holds the correct anwers

	const int SIZE = 20;				//Constant the holds the number of questions to be stored in the arrays
	int	CorrectAnswerCount,				//Int variable that holds the number of correct answers
		IncorrectAnswerCount;			//Int variable that holds the number of incorrect answers
	int missed[20];						//Int array the holds that numbers for the questions the student missed, if any.

public:
	TestGrader();
	ifstream inputFile;																										//Definition for the input file
	string setKey(string correctAnswers, string answers);																	//Function prototype for the function that sets the answer key
	string setStudent(string studentAnswers, string student);																//Function prototype for the function that sets the student answers
	string grade(string answers, string student, string verdict, int& CorrectAnswerCount, 
			int& IncorrectAnswerCount, int missed[], int SIZE);																//Function prototype for the function that grades the test 
	void display(int correctAnswerCount, int IncorrectAnswerCount, int missed[], string verdict, int SIZE);					//Function prototype for the display function 
	
};


int main()
{
	ifstream inputFile;					//Definition for the input file

	TestGrader student1;
	string studentAnswers,				//String variable that holds the student's answers after being read in from the file
		   verdict,					    //String variable that holds the message of whether or not the student passed the exam
		   answers,						//String array to hold the answer key
   		   correctAnswers,				//String variable that holds the correct anwers
		   student;						//Array to hold the student answers	

	const int SIZE = 20;				//Constant that holds the number of questions to be stored in the arrays
	int	missed[SIZE],					//Int array that holds the numbers for the questions the student missed, if any.
		CorrectAnswerCount = 0,			//Int variable that holds the number of correct answers
		IncorrectAnswerCount = 0;		//Int variable that holds the number of incorrect answers

	//Print the title to the console
	cout << "Driving Test Grader\n";

	//Open the input file
	inputFile.open("student.txt");

		//Handle the possibility of the file not opening properly
	if (!inputFile)
	{
		cout << "Input file did not open\n";
		return 10;
	}	

		//Read the file and create the student answers array
	for (int count = 0; count <= SIZE; count++)
	{
		string answer;
		inputFile >> answer;
		studentAnswers += answer;
	}
	student = student1.setStudent(studentAnswers, student);
	inputFile.close();

	//Create the answer key array	
	correctAnswers = "BDAACABACDBCDADCCBDA";
	answers = student1.setKey(correctAnswers, answers);

	//Compare the two arrays
	verdict = student1.grade(answers, student, verdict, CorrectAnswerCount, IncorrectAnswerCount, missed, SIZE);

	//Print the results
	student1.display(CorrectAnswerCount, IncorrectAnswerCount, missed, verdict, SIZE);

	return 0;

}


/*************************************
*									 *
*  TestGrader class member functions *
*									 *
**************************************/

	/***************************
	*		Constructor        *
	****************************/
TestGrader::TestGrader()
{
	//Create the arrays
	const int SIZE = 20;
	string answers[SIZE];
	string student[SIZE];
	int missed[SIZE] = {};
	int correctAnswers = 0;
}


	/*************************************
	*		       setKey                *
	* A return function that accepts     *
	* the answer array and the correct   *
	* answer string as arguments. It	 *
	* creates the answer key array from  *
	* the string of correct answers and  *
	* returns the it.				 *
	**************************************/
string TestGrader::setKey(string correctAnswers, string answers)
{
	answers = { correctAnswers };
	return answers;
}

	/*****************************************
	*		       setStudent                *
	* A return function that accepts the     *
	* student answers string and the student *
	* array as arguments. It then places the *
	* student answers string into the array. *
	* The array is then returned.            *
	*****************************************/
string TestGrader::setStudent(string studentAnswers, string student) 
{
student = { studentAnswers };
return student;
}

	/***********************************************************
	*		                  Grade		                       *
	*  A return function that accepts the answer array,        * 
	*  student array, missed question array, verdict          *
	*  variable, and size constant as arguments.			   *
	*  Answer counter variables are passed by reference.       *
	*  The student array is compared to the answer key array.  *
	*														   *			
	*  A loop counts the number of correct and incorrect       *
	*  answers, adding incorrect answer numbers to the missed  *
	*  answers array. The pass/fail verdict is determined      *
	*  based on the number stored in the correct answer        *
	*  counter. The verdict is returned.					   *
	***********************************************************/
string TestGrader::grade(string answers, string student, string verdict, int& CorrectAnswerCount, int& IncorrectAnswerCount, int missed[], int SIZE)
{
	//Compare the two arrays
	int count = 0;
	int q = 0;
		while (count < SIZE)
		{	//The answer is incorrect
			if (answers[count] != student[count])
			{
				//Add the question number to the missed question array
				missed[q] = (count + 1);
				q++;
				//Add one to the incorrect answer counter and the loop counter
				IncorrectAnswerCount++;
				count++;
			}
			//The answer is correct
			else
			{
				CorrectAnswerCount++;
				count++;
			}
		}
	//Determine if the student passed or failed	
	if (CorrectAnswerCount >= 15)
	{
		verdict = "Test passed.";
	}
	else
	{
		verdict = "Test failed.";
	}
	return verdict;
}


	/*************************************************************
	*		                  display	                         *
	*  A void function that accepts the correct and		         *
	*  incorrect answer counts, the missed question array,       *
	*  the verdict variable, and the size constant as arguments. *
	*															 *
	*  The function prints the correct and incorrect answer      *
	*  counts. A loop is used to print the missed question       *
	*  numbers from the array. Finally, the pass/fail verdict    *
	*  is printed to the console.								 * 								
	*************************************************************/
void TestGrader:: display(int CorrectAnswerCount, int IncorrectAnswerCount, int missed[], string verdict, int SIZE)
{
	cout << endl << " " << CorrectAnswerCount << " answers were correct" 
		<< endl << " " << IncorrectAnswerCount << " answers were incorrect.\n\n";
	
//Print incorrect answer numbers
		cout << "Questions with incorrect answers: \n";
		for (int q = 0; q < SIZE; q++)
		{
			if (missed[q] >= 0)
			{
				cout << " Question: "<< missed[q] << endl;
			}
		}

	cout << "\nResult: " << verdict << endl << endl;
}