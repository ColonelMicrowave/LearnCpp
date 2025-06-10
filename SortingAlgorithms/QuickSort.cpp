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

int randomisedPartition(std::vector<int>& arr, int low, int high)
{
	int randomIndex{ Random::get(low, high) };
	std::swap(arr[randomIndex], arr[high]);
	return partition(arr, low, high);
}

void quickSort(std::vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int partitionIndex{ randomisedPartition(arr, low, high) };

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
