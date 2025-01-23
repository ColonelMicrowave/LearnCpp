#include <iostream>
#include <string>
#include <cstddef>
#include <limits>
#include <algorithm>

std::size_t getNameCounts()
{
	std::cout << "How many names would you like to enter: ";

	while (true)
	{
		std::size_t length{};
		std::cin >> length;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input. Try again: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		if (!std::cin.eof() && std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cout << "Invalid input. Try again: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return length;
	}
}

void getNames(std::string* names, std::size_t length)
{
	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::string name{};
		std::getline(std::cin >> std::ws, name);

		names[i] = name;
	}
}

void printNames(std::string* names, std::size_t length)
{
	std::cout << "Here is your sorted list:\n";
	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << names[i] << '\n';
	}
}

int main()
{
	std::size_t length{ getNameCounts() };

	auto* names{ new std::string[length]{} };

	getNames(names, length);

	std::sort(names, names + length);

	printNames(names, length);

	delete[] names;

	return 0;
}
