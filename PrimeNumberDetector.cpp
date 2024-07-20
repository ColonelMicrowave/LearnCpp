#include <iostream>

int getUserInput()
{
	std::cout << "Enter a number between 1 and 10: ";
	int num{ };
	std::cin >> num;

	return num;
}

bool isPrime(int num)
{
	if (num == 2)
		return true;
	else if (num == 3)
		return true;
	else if (num == 5)
		return true;
	else if (num == 7)
		return true;
	else
		return false;
}

int main()
{
	int num{ getUserInput() };

	if (isPrime(num))
		std::cout << num << " is a prime number.\n";
	else if (num < 1)
		std::cout << "Number is less than 1.\n";
	else if (num > 10)
		std::cout << "Number is greater than 10.\n";
	else
		std::cout << num << " is not a prime number.\n";

	return 0;
}
