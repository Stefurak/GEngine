#include <iostream>
#include "Error.h"
#include <cstdlib>

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to exit..." << std::endl;
	char tmp;
	std::cin >> tmp;

	exit(1);
}