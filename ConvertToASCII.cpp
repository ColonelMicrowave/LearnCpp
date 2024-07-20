#include <iostream>

int main()
{
	std::cout << "Enter a single character: ";
	char input;
	std::cin >> input;

	std::cout << "You entered: '" << input << "', which has ASCII code " << static_cast<int>(input) << ".\n";

	return 0;
}
