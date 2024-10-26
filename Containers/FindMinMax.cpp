#include <iostream>
#include <vector>
#include <utility>
#include <limits>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMax(const std::vector<T>& v)
{
	std::size_t min{ 0 };
	std::size_t max{ 0 };

	for (std::size_t i = 1; i < v.size(); ++i)
	{
		if (v[i] < v[min])
			min = i;
		if (v[i] > v[max])
			max = i;
	}

	return { min, max };
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
	bool comma{ false };
	std::cout << "With array ( ";
	for (const auto& e : arr)
	{
		if (comma)
			std::cout << ", ";

		std::cout << e;
		comma = true;
	}
	std::cout << " ):\n";
}

int main()
{
	std::vector<int> arr{};
	std::cout << "Enter numbers to add (use -1 to stop): ";

	while (true)
	{
		int num{};
		std::cin >> num;
		if (num == -1)
			break;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		
		arr.push_back(num);
	}

	if (arr.empty())
	{
		std::cout << "No numbers entered\n";
		return 0;
	}
	else
	{
		printArray(arr);

		auto minMax{ findMinMax(arr) };
		std::cout << "Min: " << arr[minMax.first] << " at index " << minMax.first << '\n';
		std::cout << "Max: " << arr[minMax.second] << " at index " << minMax.second << '\n';
	}

	return 0;
}
