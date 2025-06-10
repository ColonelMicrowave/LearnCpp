#include <iostream>
#include <vector>
#include <utility>
#include "random.h"

int partition(std::vector<int>& arr, int low, int high)
{
	int pivot{ arr[high] };
	int i{ low - 1 };

	for (int j{ low }; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
	}

	std::swap(arr[i + 1], arr[high]);

	return (i + 1);
}

int medianOfThree(const std::vector<int>& arr, int low, int mid, int high)
{
	int lowVal{ arr[low] };
	int midVal{ arr[mid] };
	int highVal{ arr[high] };

	if ((lowVal > midVal) != (lowVal > highVal))
		return low;
	else if ((midVal > lowVal) != (midVal > highVal))
		return mid;
	else
		return high;
}

int medianOfThreePartition(std::vector<int>& arr, int low, int high)
{
	int mid{ low + ((high - low) / 2) };
	int medianIndex{ medianOfThree(arr, low, mid, high) };

	std::swap(arr[medianIndex], arr[high]);
	return partition(arr, low, high);
}

void quickSort(std::vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int partitionIndex{ medianOfThreePartition(arr, low, high) };

		quickSort(arr, low, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, high);
	}
}

int main()
{
	std::vector<int> data{ 100, 45, 78, 22, 58, 4, 5, 10 };

	quickSort(data, 0, data.size() - 1);

	for (auto& i : data)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	return 0;
}
