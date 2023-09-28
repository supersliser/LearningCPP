// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Please enter a quadratic in form 'y=mx+c' > ";
	string equation = "";
	cin >> equation;
	float m;
	float c;

	equation = equation.substr(2);
	
	int lengthToX = 0;

	while (equation.substr(lengthToX, 1) != "x") 
	{
		lengthToX++;
	}

	m = stoi(equation.substr(0, lengthToX));

	equation = equation.substr(lengthToX + 1);

	c = stoi(equation.substr(0));
	cout << "\nPlease enter the start point for x > ";
	int xstart;
	cin >> xstart;
	cout << "\nPlease enter the end point for x > ";
	int xend;
	cin >> xend;
	cout << "\nPlease enter the step size for x > ";
	int stepsize;
	cin >> stepsize;

	for (int x = xstart; x <= xend; x += stepsize)
	{
		cout << "\nx = " + to_string(x) + " >>>>>>>> y = " + to_string((m * x) + c);
	}
}
