// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Please enter where you will start > ";
    string start = "";
    cin >> start;
    cout << "\nPlease enter where you will finish > ";
    string finish = "";
    cin >> finish;
    cout << "\nPlease enter the distance this journey will take (m) > ";
    int distance = 0;
    cin >> distance;
    cout << "\nPlease enter the time this journey will take (s) > ";
    int time = 0;
    cin >> time;
    float speed = distance / time;
    string speedSTR = to_string(speed);
    int num = speedSTR.length();
    for (int i = 0; i <= speedSTR.length(); i++)
    {
        if (speedSTR.substr(i, 1) == ".")
        {
            num = i + 1;
        }
    }
    cout << "\nYour journey from " + start + " to " + finish + " will require you to move at an average speed of " + speedSTR.substr(0, num) + "m/s";
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
