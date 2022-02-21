// MakingAClass.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Handler.h"



using namespace std;
int main()
{
    std::cout << "Hello World!\n";

	Handler handler("This is a pure test");

	std::string value = handler.getName();
	printf("%s", value);

}
