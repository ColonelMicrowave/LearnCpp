#include <iostream>
#include <limits>

struct Fraction
{
	int numerator{};
	int denominator{};
};

int inputValidation()
{
	int x{};
	while (true)
	{
		std::cin >> x;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please try again: ";
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return x;
		}
	}
}

Fraction getFraction()
{
	Fraction fraction{};

	while (true)
	{
		std::cout << "Enter the numerator: ";
		fraction.numerator = inputValidation();

		std::cout << "Enter the denominator: ";
		fraction.denominator = inputValidation();
		if (fraction.denominator == 0)
		{
			std::cout << "Denominator cannot be 0. Please try again.\n ";
		}
		else
		{
			break;
		}

	}

	return fraction;
}

Fraction multiplyFractions(const Fraction& fraction1, const Fraction& fraction2)
{
	Fraction result{};
	result.numerator = fraction1.numerator * fraction2.numerator;
	result.denominator = fraction1.denominator * fraction2.denominator;
	return result;
}

int main()
{
	std::cout << "Fraction 1 \n";
	Fraction fraction1{ getFraction() };

	std::cout << "Fraction 2: \n";
	Fraction fraction2{ getFraction() };

	// Getting result...
	Fraction result{ multiplyFractions(fraction1, fraction2) };

	std::cout << "Your fractions multiplied: " << result.numerator << "/" << result.denominator << '\n';

	return 0;
}
