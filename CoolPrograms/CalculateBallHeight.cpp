#include <iostream>

double getBuildingHeight()
{
	std::cout << "Enter the height of the building in meters: ";
	double height{};
	std::cin >> height;

	return height;
}

double calculateHeight(double initialHeight, int seconds)
{
	double distanceFallen{ 0.5 * (9.8 * seconds * seconds) };
	double currentHeight{ initialHeight - distanceFallen };

	return currentHeight;
}

void printHeight(double height, int seconds)
{
	if (height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

int main()
{
	double height{ getBuildingHeight() };

	printHeight( calculateHeight(height, 0), 0 );
	printHeight( calculateHeight(height, 1), 1 );
	printHeight( calculateHeight(height, 2), 2 );
	printHeight( calculateHeight(height, 3), 3 );
	printHeight( calculateHeight(height, 4), 4 );
	printHeight( calculateHeight(height, 5), 5 );
}
