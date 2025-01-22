#include <iostream>
#include <iterator>
#include <utility>

int main()
{
	int array[]{ 30, 50, 20, 10, 40 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
	{
		int largestIndex{ startIndex };

		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			if (array[largestIndex] < array[currentIndex])
			{
				largestIndex = currentIndex;
			}
		}

		std::swap(array[startIndex], array[largestIndex]);
	}

	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}
