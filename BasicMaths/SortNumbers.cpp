#include <iostream>
#include <limits>
#include <algorithm>

void sortNum(int& lesser, int& greater)
{
    if (lesser > greater)
    {
        std::swap(lesser, greater);
    }
}

int getNum()
{
	while (true)
	{
		std::cout << "Enter a number: ";
		int num{};
		std::cin >> num;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please try again.\n";
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return num;
		}
	}
}

int main()
{
	int num1{ getNum() };
	int num2{ getNum() };

    sortNum(num1, num2);
	std::cout << "The smaller number is: " << num1 << '\n';
	std::cout << "The larger number is: " << num2 << '\n';

    return 0;
}
