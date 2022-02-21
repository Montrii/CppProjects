#include "Handler.h"


Handler::Handler(unsigned int age)
{
	AGE = age;
}


Handler::Handler()
{

}

Handler::Handler(std::string name)
{
	NAME = name;
}


unsigned int Handler::getAge()
{
	return AGE;
}

std::string Handler::getName()
{
	return NAME;
}