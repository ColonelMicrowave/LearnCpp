#include <iostream>

int main()
{
	char c{ 'a' };
	while (c <= 'z')
	{
		std::cout << c << ": " << static_cast<int>(c) << '\n'; // print the character and its ASCII value
		++c; // increment the character to the next letter
	}

	return 0;
}
