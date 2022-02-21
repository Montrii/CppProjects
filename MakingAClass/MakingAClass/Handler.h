#pragma once


#include <iostream>
class Handler
{
public:
	// Variables
	std::string NAME;
	unsigned int AGE;


	// Constructors
	Handler(std::string name);
	Handler();
	Handler(unsigned int age);


	unsigned int getAge();
	std::string getName();


};

