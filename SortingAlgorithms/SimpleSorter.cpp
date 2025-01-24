#include <iostream>
#include <iterator>
#include <utility>

bool descending(int x, int y)
{
	return x < y;
}

bool ascending(int x, int y)
{
	return x > y;
}

bool oddsFirst(int x, int y)
{
	if ((x % 2 == 0) && !(y % 2 == 0))
		return true;
	else if (!(x % 2 == 0) && (y % 2 == 0))
		return false;
	else
		return ascending(x, y);
}

bool evensFirst(int x, int y)
{
	if ((x % 2 == 0) && !(y % 2 == 0))
		return false;
	else if (!(x % 2 == 0) && (y % 2 == 0))
		return true;
	else
		return ascending(x, y);
}

void selectionSort(int* array, int length, bool (*comparisonFnc)(int, int) = ascending)
{
	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
	{
		int bestIndex{ startIndex };

		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			if (comparisonFnc(array[bestIndex], array[currentIndex]))
			{
				bestIndex = currentIndex;
			}
		}

		std::swap(array[startIndex], array[bestIndex]);
	}
}

void printArray(int* array, int length)
{
	if (!array)
		return;

	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

int main()
{
	int array[]{ 3, 5, 2, 1, 4 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	selectionSort(array, length);
	printArray(array, length);

	selectionSort(array, length, descending);
	printArray(array, length);

	selectionSort(array, length, evensFirst);
	printArray(array, length);

	selectionSort(array, length, oddsFirst);
	printArray(array, length);

	return 0;
}
