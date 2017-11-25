#include <iostream>
using namespace std;

int getValue(int);

int main()
{
	int x = 2;

	cout << getValue(x) << endl;
	return 0;
}

int getValue(int num)
{
	return num + 5;
}