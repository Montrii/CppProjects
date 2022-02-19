// MyFirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <type_traits>
using namespace std;


// Creating a new template with the Type of <T>
// T is a generic datatype.
template<typename T>


// passing variables by reference allows us to manipulate the actual variable content without making a copy of it.
// use & for passing by reference


// We can create multiple different instances of the same function by overloading it. 
void Swap(T& a, T& b)
{
	T temp = a; 
	a = b;
	b = temp;

	if (std::is_same<T, int>::value)
	{
		cout << "hey this is a integer!";
	}

	// " :: " are used to define functions outside of a class or to access class static variables.
}

int main()
{

	/*
	float annualSalary;

	// Output.
	cout << "Please enter your annual Salary: "; //outputing to the console
	// Input.
	cin >> annualSalary;
	cout << "Your monthly salary is: " << annualSalary / 12 << endl;

	char character = 'a'; // single character

	cout << character;

	unsigned int a = 5;

	*/
	char a = 'a';
	char b = 'b';

	// you can also invoke your generic function like this
	// FUNCTIONNAME<Type>(...);
	Swap(a,b);
	cout << a << " -- " << b << endl;
	system("pause>0");
	return 0;
} 