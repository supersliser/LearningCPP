// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const double pi = 3.14159265358979323846;
    cout << "Please enter the radius of the tank > ";
    int radius = 0;
    cin >> radius;
    cout << "\nPlease enter the height of the tank (m) > ";
    int height = 0;
    cin >> height;
    float volume = pi * (radius * 2) * height;
    string volumeSTR = to_string(volume);
    int num = volumeSTR.length();
    for (int i = 0; i <= volumeSTR.length(); i++)
    {
        if (volumeSTR.substr(i, 1) == ".")
        {
            num = i + 4;
        }
    }
    cout << "\nThis tank has a volume of " + volumeSTR.substr(0, num) + "m^3";
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
