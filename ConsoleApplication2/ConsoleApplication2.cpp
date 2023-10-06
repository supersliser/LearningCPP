// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Point
{
public:
	int x;
	int y;
};

class PointNode {
public:
	Point data;
	PointNode* next;
};

class PointList {
private:
	PointNode* head;
public:
	PointList() : head(nullptr) {}

	void Add(Point inputdata)
	{
		PointNode* newNode = new PointNode();
		newNode->data = inputdata;
		newNode->next = nullptr;

		if (!head) {
			head = newNode;
		}
		else {
			PointNode* currentNode = head;
			while (currentNode->next != nullptr) {
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
	}

	void Clear()
	{
		while (head != nullptr) {
			PointNode* temp = head;
			head = head->next;
			free(&temp);
		}
	}

	Point getItem(int item)
	{
		PointNode* currentNode = head;
		for (int i = 0; i < item; i++)
		{
			if (currentNode == nullptr)
			{
				// Handle out-of-bounds condition here
				// You can throw an exception or return a default value as needed.
			}
			currentNode = currentNode->next;
		}
		return currentNode->data;
	}

	int Count()
	{
		int output = 0;
		PointNode* currentNode = head;
		while (currentNode != nullptr)
		{
			output++;
			currentNode = currentNode->next;
		}
		return output;
	}

	~PointList()
	{
		Clear(); // Destructor clears the list to prevent memory leaks
	}
};

class GraphDrawer {
public:
	PointList pointsOnGraph;
	void writePositiveGradient(int minX, int maxX, int minY = 0, int maxY = 0)
	{
		int maxYLength = calculateMaxYLength();
		int maxXLength = calculateMaxXLength();
		cout << writeYStarter(maxY, maxYLength);
		cout << writeX(pointsOnGraph.getItem(0).x, pointsOnGraph.getItem(0).y, maxX, maxYLength, maxXLength);
		cout << "\n";
		for (int i = maxY; i >= 1; i--)
		{
			Point pointItem = pointsOnGraph.getItem(i);
			cout << writeYStarter(maxY, maxYLength);
			cout << writeX(pointItem.x, i, maxX, maxYLength, maxXLength);
			cout << "\n";
		}
		cout << writeRowLines(maxXLength, minX, maxX);
		cout << writeXBottom(maxXLength, minX, maxX, maxYLength);
		cout << writeRowLines(maxXLength, minX, maxX);
		for (int i = -1; i >= minY; i--)
		{
			Point pointItem = pointsOnGraph.getItem(i);
			cout << writeYStarter(maxY, maxYLength);
			cout << writeX(pointItem.x, pointItem.y, maxX, maxYLength, maxXLength);
			cout << "\n";
		}
	}
private:
	int calculateMaxYLength()
	{
		int output = 0;
		for (int i = 0; i < pointsOnGraph.Count(); i++)
		{
			if (output < pointsOnGraph.getItem(i).y)
			{
				output = pointsOnGraph.getItem(i).y;
			}
		}
		return output;
	}
	int calculateMaxXLength()
	{
		int output = 0;
		for (int i = 0; i < pointsOnGraph.Count(); i++)
		{
			if (output < pointsOnGraph.getItem(i).x)
			{
				output = pointsOnGraph.getItem(i).x;
			}
		}
		return output;
	}
	string writeX(int x, int y, int maxX, int maxYLength, int xSize)
	{
		string output = writeYStarter(y, maxYLength);
		for (int i = 0; i < x * xSize; i++)
		{
			output += " ";
		}
		output += "^";
		return output;
	}
	string writeX(int x1, int x2, int y, int maxX, int maxYLength, int xSize)
	{
		string output = writeYStarter(y, maxYLength);
		{
			output += " ";
		}
		output += "/";
		for (int i = x1 + 1; i < x2 * xSize; i++)
		{
			output += " ";
		}
		output += "\\";
		return output;
	}
	string writeYStarter(int y, int maxYLength)
	{
		string output = to_string(y);
		for (int i = 0; i <= maxYLength; i++)
		{
			output += " ";
		}
		output += "|";
		return output;
	}
	string writeRowLines(int xSize, int minX, int maxX)
	{
		string output = "";
		for (int i = minX; i <= maxX * xSize; i++)
		{
			output += "-";
		}
		return output;
	}
	string writeXBottom(int xSize, int minX, int maxX, int maxYLength)
	{
		string output = writeYStarter(0, maxYLength);
		for (int i = minX; i <= maxX; i++)
		{
			output += i;
			for (int j = to_string(i).length(); j <= xSize; j++)
			{
				output += " ";
			}
		}
		return output;
	}
};

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

	GraphDrawer drawer;

	PointList points;

	for (int y = (m * xstart) + c; y <= (m * xend) + c; y++)
	{
		Point item;
		item.x = (y - c) / m;
		item.y = y;
		points.Add(item);
	}

	drawer.pointsOnGraph = points;

	if (m > 0)
	{
		drawer.writePositiveGradient(xstart, xend, (m * xstart) + c, (m * xend) + c);
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
