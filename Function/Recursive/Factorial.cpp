#include <iostream>
#include <vector>

int factorial(int n)
{
	if (n == 1)
		return 1;

	return factorial(n - 1) * n;
}

int main()
{
	int result{ factorial(10) };

	std::cout << result << '\n';

	return 0;
}
