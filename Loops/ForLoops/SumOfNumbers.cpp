#include <iostream>

int sumOfNumbers(int value)
{
	int sum{ 0 };
	
	for (int i = 0; i <= value; i++)
	{
		sum += i;
	}

	return sum;
}

int main()
{
	std::cout << "Enter an integer: ";
	int userInt;
	std::cin >> userInt;

	std::cout << "The sum of all numbers from 0 to " << userInt << " is: " << sumOfNumbers(userInt) << '\n';

	return 0;
}
