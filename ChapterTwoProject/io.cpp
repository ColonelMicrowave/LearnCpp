#include <iostream>
#include "io.h"

int readNumber()
{
	std::cout << "Enter a number: ";
	int userNumber;
	std::cin >> userNumber;

	return userNumber;
}

void writeAnswer(int sum)
{
	std::cout << "The sum of the two numbers is: " << sum << '\n';
}
