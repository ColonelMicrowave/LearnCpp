#include <iostream>

int getUserInput()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}


int main()
{
	int num1{ getUserInput() };
	int num2{ getUserInput() };

	std::cout << num1 << " + " << num2 << " = " << num1 + num2 << ".\n";
	std::cout << num1 << " - " << num2 << " = " << num1 - num2 << ".\n";

	return 0;
}
