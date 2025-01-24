#include <iostream>
#include <limits>
#include <functional>

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int userInt()
{
	std::cout << "Enter an integer: ";

	while (true)
	{
		int num{};
		std::cin >> num;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input. Try again: ";
			ignoreLine();

			continue;
		}
		if (!std::cin.eof() && std::cin.peek() != '\n')
		{
			std::cout << "Invalid input. Try again: ";
			ignoreLine();

			continue;
		}

		ignoreLine();

		return num;
	}
}

char userOperation()
{
	std::cout << "Enter the operation (+, -, *, /): ";

	while (true)
	{
		char operation{};
		std::cin >> operation;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input. Try again: ";
			ignoreLine();

			continue;
		}
		if (!std::cin.eof() && std::cin.peek() != '\n')
		{
			std::cout << "Invalid input. Try again: ";
			ignoreLine();

			continue;
		}

		ignoreLine();

		return operation;
	}
}

int addition(int x, int y)
{
	return x + y;
}

int subtraction(int x, int y)
{
	return x - y;
}

int multiplication(int x, int y)
{
	return x * y;
}

int division(int x, int y)
{
	return x / y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+': return &addition;
	case '-': return &subtraction;
	case '*': return &multiplication;
	case '/': return &division;

	default:
		return nullptr;
	}
}

int main()
{
	int x{ userInt() };
	int y{ userInt() };
	char op{ userOperation() };

	ArithmeticFunction fcn{ getArithmeticFunction(op) };
	if (fcn)
	{
		std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';
	}

	return 0;
}
