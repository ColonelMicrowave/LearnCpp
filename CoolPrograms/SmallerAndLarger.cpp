#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int num1{ };
	std::cin >> num1;

	std::cout << "Enter a larger integer: ";
	int num2{ };
	std::cin >> num2;

	if (num1 > num2)
	{
		std::cout << "Swapping the values\n";
		int smallNum{ num2 };
		int largeNum{ num1 };
		std::cout << "The smaller value is " << smallNum << '\n';
		std::cout << "The larger value is " << largeNum << '\n';
	}
	if (num1 == num2)
	{
		std::cout << "The numbers are the same\n";
	}
	else
	{
		std::cout << "The smaller value is " << num1 << '\n';
		std::cout << "The larger value is " << num2 << '\n';
	}

	return 0;
}
