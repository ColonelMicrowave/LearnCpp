#include <iostream>

int getUserInput()
{
	std::cout << "Enter an integer: ";
	int input{ };
	std::cin >> input;

	return input;
}

int doubleNumber(int num)
{
	return num * 2;
}

int main()
{
	
	std::cout << "Double that number is: " << doubleNumber(getUserInput()) << std::endl;

	return 0;
}
