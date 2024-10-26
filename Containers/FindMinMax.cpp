#include <iostream>
#include <vector>
#include <utility>

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
	std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };
	printArray(v1);

	auto m1{ findMinMax(v1) };
	std::cout << "The min element has index " << m1.first << " and the min value is " << v1[m1.first] << "\n";
	std::cout << "The max element has index " << m1.second << " and the max value is " << v1[m1.second] << "\n\n";

	std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
	printArray(v2);

	auto m2{ findMinMax(v2) };
	std::cout << "The min element has index " << m2.first << " and the min value is " << v2[m2.first] << "\n";
	std::cout << "The max element has index " << m2.second << " and the max value is " << v2[m2.second] << "\n\n";

	return 0;
}
