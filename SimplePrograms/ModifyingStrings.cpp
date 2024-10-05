#include <iostream>
#include <string>

int main()
{
	std::string str{ "I saw a red car yesterday." };

	str.replace(8, 3, "blue");

	std::cout << str << '\n';

	return 0;
}
