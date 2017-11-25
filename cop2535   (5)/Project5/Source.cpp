//Rebecca Flake
//COP2535.CM1
/*This program will create a family tree using a binary tree structure. 
It will then find all of the cousins for a given person and print them to the console. */

#include<iostream>
#include "Header.h"
#include <string>
using namespace std;

int main(int argc, char** argv)
{
//The grandparents - Generation One
	//Maternal grandmother
	Person jasmine("Jasmine", female);
	//Maternal grandfather
	Person alphonse("Alphonse", male);
	//Paternal grandmother
	Person rin("Rin", female);
	//Paternal grandfather
	Person leon("Leon", male);

//Generation Two
	//Jasmine and Alphonse are the parents of Josephine, Liliana, and Laurent
	Person *pJosephine = jasmine.addChild(new Person("Josephine", female));					//add Josephine
	alphonse.addChild(pJosephine);
	Person *pLiliana = jasmine.addChild(new Person("Liliana", female));						//add Liliana
	alphonse.addChild(pLiliana);
	Person *pLaurent = jasmine.addChild(new Person("Laurent", male));						//add Laurent
	alphonse.addChild(pLaurent);
	//Rin and Leon are the parents of Roy and Gaius
	Person *pRoy = rin.addChild(new Person("Roy", male));									//add Roy
	leon.addChild(pRoy);
	Person *pGaius = rin.addChild(new Person("Gaius", male));								//add Gaius
	leon.addChild(pGaius);

//Generation Three
	//Josephine and Roy are the parents of Marika
	Person *pMarika = pJosephine->addChild(new Person("Marika", female));					//add Marika
	pRoy->addChild(pMarika);
	//Laurent is the father of Alex and Vivian
	Person *pAlex = pLaurent->addChild(new Person("Alex", male));							//add Alex
	Person *pVivian = pLaurent->addChild(new Person("Vivian", female));						//add Vivian
	//Liliana is the mother of  Florence 
	Person *pFlorence = pLiliana->addChild(new Person("Florence", female));					//add Florence
	//Gaius is the father of Morgan
	Person *pMorgan = pGaius->addChild(new Person("Morgan", male));							//add Morgan
	
	//Add the cousins for each child
	pMarika->addCousins(pMarika);
	pAlex->addCousins(pAlex);
	pVivian->addCousins(pVivian);
	pFlorence->addCousins(pFlorence);
	pMorgan->addCousins(pMorgan);


	//Print the cousins to the console
	cout << *pMarika << endl << endl;
	cout << *pAlex << endl << endl;
	cout << *pVivian << endl << endl;
	cout << *pFlorence << endl << endl;
	cout << *pMorgan << endl << endl;


	return 0;
}
