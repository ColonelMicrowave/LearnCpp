#include <iostream>
#include <vector>
#include <string>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& value)
{
	for (const auto& element : arr)
	{
		if (element == value)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::vector<std::string_view> names{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string name{};
	std::cin >> name;

	bool found{ isValueInArray<std::string_view>(names, name) };

	if (found)
	{
		std::cout << name << " was found.\n";
	}
	else
	{
		std::cout << name << " was not found.\n";
	}

	return 0;
}
