#include <iostream>

void fizzBuzz(int n)
{
	for (int i{ 1 }; i <= n; i++)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			std::cout << "fizzbuzz" << '\n';
		}
		else if (i % 3 == 0)
		{
			std::cout << "fizz" << '\n';
		}
		else if (i % 5 == 0)
		{
			std::cout << "buzz" << '\n';
		}
		else
		{
			std::cout << i << '\n';
		}
	}
}

int main()
{
	std::cout << "Enter a number: ";
	int userInput;
	std::cin >> userInput;

	fizzBuzz(userInput);
}
