#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter your full name: ";
	std::string name{ };
	std::getline(std::cin >> std::ws, name); // std::ws used so std::cin will ignore leading whitespace and getline will read the entire line including spaces
	int nameLength{ static_cast <int>(name.length()) }; // static_cast <int> used to convert the result of name.length() to a signed integer so we do not mix signed and unsigned integers

	std::cout << "Enter your age: ";
	int age{ }; // age is a signed integer so we can add it to nameLength
	std::cin >> age;

	std::cout << "Your age + length of name is: " << age + nameLength << "\n";
	return 0;
}
