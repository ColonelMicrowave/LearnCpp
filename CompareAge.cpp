#include <iostream>
#include <string>
#include <string_view>

std::string getName(int num)
{
	std::cout << "Enter name of person #" << num << ": ";
	std::string name{ };
	std::getline(std::cin >> std::ws, name); // std::ws is used to ignore whitespace characters so we can read the full name with spaces

	return name;
}

int getAge(std::string_view name) // std::string_view is used to pass the string by reference without copying it which is expensive
{
	std::cout << "Enter the age of " << name << ": ";

	int age{ };
	std::cin >> age;

	return age;
}

void compareAge(int age1, int age2, std::string_view name1, std::string_view name2)
{
	if (age1 > age2)
	{
		std::cout << name1 << " (age " << age1 << ")" << " is older than " << name2 << " (age " << age2 << ").\n";
	}
	else if (age1 < age2)
	{
		std::cout << name2 << " (age " << age2 << ")" << " is older than " << name1 << " (age " << age1 << ").\n";
	}
	else
	{
		std::cout << name1 << " (age " << age1 << ")" << " is the same age as " << name2 << " (age " << age2 << ").\n";
	}
}


int main()
{
	const std::string name1{ getName(1) };
	const int age1 { getAge(name1) };

	const std::string name2{ getName(2) };
	const int age2 { getAge(name2) };

	compareAge(age1, age2, name1, name2);

	return 0;
}
