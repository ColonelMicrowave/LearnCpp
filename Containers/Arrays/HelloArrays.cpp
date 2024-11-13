#include <iostream>
#include <array>

int main()
{
	std::array<char, 5> hello{ 'h', 'e', 'l', 'l', 'o' };

	for (char c : hello)
	{
		std::cout << c;
	}
	std::cout << '\n';

	return 0;
}
