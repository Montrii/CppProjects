// MyFirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	float annualSalary;

	// Output.
	cout << "Please enter your annual Salary: "; //outputing to the console
	// Input.
	cin >> annualSalary;
	cout << "Your monthly salary is: " << annualSalary / 12 << endl;

	char character = 'a'; // single character

	cout << character;
} 