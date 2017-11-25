#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum Gender {male, female};

class Person
{
private:
	//Tree node struct to build the tree
		string name;															//Variable to hold the person's name
		Gender gender;															//Variable to hold the person's gender
		vector<Person *> parents;												//Vector to hold the person's parents
		vector<Person *> children;												//Vector to hold the person's children
		vector<Person *> cousins;												//Vector to hold the person's cousins
		void addParent(Person *p) { parents.push_back(p); }						//Function that adds a person's parent to the parents vector
		
public:
	Person(string name, Gender g)												//Creates a person object with a name and gender
	{
		this->name = name;
		gender = g;
	}
	Person *addChild(string name, Gender g);									//Function that creates a person who is the child of another
	Person *addChild(Person *p);												//Adds an existing person to the child vector of another

	friend ostream &operator << (ostream &out, Person p);						//Overloaded output operator that prints the contents of the vectors for a person

	//Member functions for getting various information 
	string getName() const { return name; };									//Function that returns the name of a person
	Gender getGender() const { return gender; };								//Function that returns the gender of a person
	int getNumChildren() const { return children.size(); }						//Function that gets the length of the children vector for a person
	int getNumParents() const { return parents.size(); }						//Function that gets the length of the parents vector for a person
	int getNumCousins() const { return cousins.size(); }						//Function that gets the length of the cousins vector for a person
	Person *getChild(int k) const;												//Function that gets a child from the vector 
	Person *getParent(int k) const;												//Function that gets a parent from the vector
	Person *getCousin(int k) const;												//Function that gets a parent from the vector
	void addCousins(Person *p);													//Function that adds a person's cousins to the cousins vector
};

/****************************************************************************
/****************************************************************************/

/*******************************************************************
*								addChild						   *
* Accepts a name and a gender as arguments to create a new person. *
* This new person is added as a child for the person object that   *
* called the function.											   *
*******************************************************************/
Person *Person::addChild(string name, Gender g)
{
	Person *child = new Person(name, g);
	child->addParent(this);		//I am a parent of this child
	children.push_back(child);	//this is one of my children
	return child;
}
/************************************************************************
*								addChild								*
* Accepts a person as an argument. This person is added to the children * 
* vector of person object that called the function.				        *
************************************************************************/
Person *Person::addChild(Person* child)
{
	child->addParent(this);		//I am a parent of this child
	children.push_back(child);  //This is one of my children
	return child;
}

/***********************************************************************
*							   addCousins							   *
* Accepts a pointer to a person as an argument and gets the cousin(s)  *
* of this person. A series of for loops are used to search through the *
* person's family tree to find the person's cousins.				   *
***********************************************************************/
void Person::addCousins(Person* p)

{
	Person* person = p;																//The person whose cousins are being found
//look at the person's parents vector
	for (int P = 0; P < person -> parents.size(); P++)
	{ 
		Person* Parent = person -> getParent(P); 									//The parent of person
	//Step up to the first generation level
		for (int G = 0; G < Parent ->parents.size()-1; G++)
		{
			Person* GParent = Parent-> getParent(G);								//The grandparent of person.
		//Step down to the vector containing the second generation 
			for(int S=0; S< GParent -> children.size(); S++)
			{
				Person* Sib = GParent -> getChild(S);								//The aunt/uncle of the person. The second generation member will be ignored if they are the parent of person
				 if(Sib != Parent)													
					{ 
					//Step down to vector containing the third generation
					for(int C = 0;C< Sib -> children.size();C++)
					{
						Person* cousin = Sib -> getChild(C);						//A cousin of person
						cousins.push_back(cousin);									//add this cousin to the cousin vector for person
					}
				}
			}
		}
	}
}


/****************************************************************************
*								getParent								    *
* Accepts an index as an argument and uses it to search the parents vector. *
* if the index is valid it will return a pointer to the specified element.  *
****************************************************************************/
Person * Person::getParent(int k) const
{	//Get the parent if the index is in range
	if (k < 0 || k >= parents.size())
	{
		cout << "Error indexing parents vector." << endl;
		exit(1);
	}
	return parents[k];
}

/*****************************************************************************
*								getChild								     *
* Accepts an index as an argument and uses it to search the children vector. *
* if the index is valid it will return a pointer to the specified element.   *
******************************************************************************/
Person * Person::getChild(int k) const
{	//get the child if the index with within range
	if (k < 0 || k >= children.size())
	{
		cout << "Error indexing childrens vector." << endl;
		exit(1);
	}
	return children[k];
}
/****************************************************************************
*								getCousin								    *
* Accepts an index as an argument and uses it to search the cousins vector. *
* if the index is valid it will return a pointer to the specified element.  *
****************************************************************************/
Person * Person::getCousin(int k) const
{	//get the cousin if the index is within range
	if (k < 0 || k >= cousins.size())
	{
		cout << "Error indexing cousins vector." << endl;
		exit(1);
	}
	return cousins[k];
}

/************************************
* Overloaded stream output operator *
************************************/
ostream &operator << (ostream &out, Person p)
{
	out << "Name: " << p.name << "\n";
	//Print the parents
	if (p.parents.size() > 0)
	{out << "Parent(s): ";}
	for (int k = 0; k < p.parents.size(); k++)
	{out << " " << p.parents[k]->name << ' ';}

	//Print the children
	if (p.children.size() > 0)
	{out << "\nChildren: ";}
	for (int k = 0; k < p.children.size(); k++)
	{out << " " << p.children[k]->name << ' ';}

	//Print the cousins
	if (p.cousins.size() > 0)
	{cout << "\nCousin(s): ";}
	for (int k = 0; k < p.cousins.size(); k++)
	{cout << " " << p.cousins[k]->name << ' ';}

	return out;
}
#endif*/