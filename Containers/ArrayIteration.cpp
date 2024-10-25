#include <iostream>
#include <vector>
#include <limits>
#include <string_view>

template<typename T>
void printArray(const std::vector<T>& arr)
{

	for (std::size_t i{ 0 }; i < arr.size(); ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

template<typename T>
int findIndex(const std::vector<T>& arr, T value)
{
	for (std::size_t i{ 0 }; i < arr.size(); ++i)
	{
		if (arr[i] == value)
			return static_cast<int>(i);
	}

	return -1; // indicates value not found
}

// Passing in the low and high values allows the compiler to deduce the type of T
template<typename T>
T getUserNum(T low, T high)
{
	T num{};
	do
	{
		std::cout << "Enter a number between 1 and 9: ";
		std::cin >> num;

		if (std::cin.fail())
			std::cin.clear(); // clear error flags

		// ignore any extra characters in the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (num < 1 || num > 9);

	return num;
}

int main()
{
	std::vector arr{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
	auto element{ getUserNum(1.0, 9.0) };

	printArray(arr);
	
	int index{ findIndex(arr, element) };

	if (index != -1)
		std::cout << "The number " << element << " has index " << index << '\n';
	else
		std::cout << "The number " << element << " was not found\n";

	return 0;
}
