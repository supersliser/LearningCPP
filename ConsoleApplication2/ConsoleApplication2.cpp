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

	m = stof(equation.substr(0, lengthToX));

	equation = equation.substr(lengthToX + 1);

	c = stof(equation.substr(0));
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

class GraphDrawer {
	
};

struct Point
{
public:
	int x;
	int y;
};

class PointNode {
public:
	Point data;
	PointNode *next;
};

class PointList {
private:
	PointNode *head;

public:
	void Add(Point inputdata)
	{
		PointNode* newNode = new PointNode();
		newNode->data = inputdata;
		PointNode* currentNode = head;
		while (currentNode != NULL)
		{
			currentNode = head->next;
		}
		currentNode->next = newNode;
	}
	void Clear()
	{

	}
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
