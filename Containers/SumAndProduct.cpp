#include <iostream>
#include <vector>

int main()
{
	// Practicing with std::vector
	std::vector squareNumbers{ 1, 4, 9, 16, 25 };
	std::vector<double> highestTemperature(365);

	// Using vectors
	std::cout << "Enter three integers: ";
	std::vector<int> numbers(3);
	std::cin >> numbers[0] >> numbers[1] >> numbers[2];

	std::cout << "The sum is: " << numbers[0] + numbers[1] + numbers[2] << "\n";
	std::cout << "The product is: " << numbers[0] * numbers[1] * numbers[2] << "\n";

	return 0;
}
