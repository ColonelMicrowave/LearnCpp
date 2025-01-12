#include <iostream>

void printString(const char str[])
{
	while (*str != '\0')
	{
		std::cout << *str;

		++str;
	}
	std::cout << '\n';
}

void printBackwards(const char str[])
{
	const char *ptr{ str };

	while (*ptr != '\0')
	{
		++ptr;
	}

	while (ptr-- != str)
	{
		std::cout << *ptr;
	}
	std::cout << '\n';
}

int main()
{
	const char str[]{ "Hello world!" };

	printString(str);
	printString("This is pretty cool!");

	std::cout << "\n";

	printBackwards(str);
	printBackwards("This is pretty cool!");

	return 0;
}
