#include <iostream>

int main()
{
	int outer{ 5 };
	while (outer >= 1)
	{
		int inner{ outer };
		while (inner >= 1)
		{
			std::cout << inner << ' ';
			--inner;
		}

		std::cout << '\n';
		--outer;
	}

	return 0;
}
