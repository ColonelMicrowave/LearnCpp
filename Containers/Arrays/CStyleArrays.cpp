#include <iostream>

int main()
{
	constexpr int squares[4]{ 0, 1, 4, 9 };

	while (true)
	{
		std::cout << "Enter a single digit integer, or -1 to quit: ";
		int val{};
		std::cin >> val;

		if (val == -1)
		{
			std::cout << "Bye\n";
			return 0;
		}

		bool found{ false };
		for (const auto& num : squares)
		{
			if (val == num)
			{
				found = true;
				break;
			}
		}

		if (found)
		{
			std::cout << val << " is a perfect square\n";
		}
		else
		{
			std::cout << val << " is not a perfect square\n";
		}
	}
}
