#include <iostream>

void denaryToBinary(unsigned int denary)
{
	if (denary > 1)
	{
		denaryToBinary(denary / 2);
	}

	std::cout << denary % 2;
}

int main()
{
	denaryToBinary(static_cast<unsigned int>(-15));

	return 0;
}
