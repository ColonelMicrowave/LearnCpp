#include <iostream>

double getUserNumber()
{
	std::cout << "Enter a number: ";
	double num{};
	std::cin >> num;

	return num;
}

char getMathematicalOperation()
{
	std::cout << "Enter a mathematical operation (+, -, *, /): ";
	char op{};
	std::cin >> op;

	return op;
}

double calculate(double num1, double num2, char op)
{
	if (op == '+')
		return num1 + num2;
	else if (op == '-')
		return num1 - num2;
	else if (op == '*')
		return num1 * num2;
	else if (op == '/')
		return num1 / num2;
	else
		return 0.0;
}

int main()
{
	double num1{ getUserNumber() };
	double num2{ getUserNumber() };

	char op{ getMathematicalOperation() };

	double result{ calculate(num1, num2, op) };

	std::cout << num1 << " " << op << " " << num2 << " = " << result << '\n';

	return 0;
}
