#include <iostream>

void printResult(int num1, int num2, char op)
{
	switch (op)
	{
	case '+':
		std::cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
		break;
	case '-':
		std::cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
		break;
	case '*':
		std::cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
		break;
	case '/':
		std::cout << num1 << " / " << num2 << " = " << num1 / num2 << '\n';
		break;
	case '%':
		std::cout << num1 << " % " << num2 << " = " << num1 % num2 << '\n';
		break;
	default:
		std::cout << "Invalid operator\n";
		break;
	}
}

int main()
{
	std::cout << "Enter an integer: ";
	int num1{ };
	std::cin >> num1;

	std::cout << "Enter another integer: ";
	int num2{ };
	std::cin >> num2;

	std::cout << "Enter an operator (+, -, *, /, %): ";
	char op{ };
	std::cin >> op;

	printResult(num1, num2, op);

	return 0;
}
