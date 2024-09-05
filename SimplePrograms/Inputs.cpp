#include <iostream>

// Function to allow user to input 3 numbers

int main()
{
	int num1{ }, num2{ }, num3{ };
	std::cout << "Enter 3 numbers separated by spaces: ";
	std::cin >> num1 >> num2 >> num3;
	std::cout << "You entered: " << num1 << ", " << num2 << ", and " << num3 << ".\n";

	return 0;
}
