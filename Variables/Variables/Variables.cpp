// Variables.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>


using namespace std;
int main()
{

	int yearOfBirth = 1995;
	char gender = 'f'; 
	bool male = true; 

  //  std::cout << "Hello World!\n";

	//showcasing you how much bytes the variables/arrays are using.
//	cout << sizeof(male); 



	//showcasing you the min value of an integer
	cout << INT_MIN;


	// datatype for only positive int values -> unsigned int
	// it does not use a bit for sign ( - | + ), so a bigger number can be part of int
	unsigned int value = 1;

	int MAX = INT_MAX;
	MAX = MAX + 1;
	// this will cause a number overflow, causing the int to start from the last value possible


	// getting the ascii value of a character
	cout << (int)'a' << endl;
	cout << int('a') << endl;



	system("pause>0");
}