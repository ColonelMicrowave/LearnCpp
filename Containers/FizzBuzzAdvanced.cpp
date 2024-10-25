#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

int main()
{
	const std::vector<std::string_view> fizzbuzz { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
	const std::vector<int> divisors { 3, 5, 7, 11, 13, 17, 19 };

	assert((fizzbuzz.size() == divisors.size()) && "FizzBuzz and Divisors size mismatch");

	for (int i{ 1 }; i <= 150; ++i)
	{
		bool isDivisible{ false };
		for (std::size_t j{ 0 }; j < divisors.size(); ++j)
		{
			if (i % divisors[j] == 0)
			{
				std::cout << fizzbuzz[j];
				isDivisible = true;
			}
		}

		if (!isDivisible)
			std::cout << i;
		std::cout << '\n';
	}
}
