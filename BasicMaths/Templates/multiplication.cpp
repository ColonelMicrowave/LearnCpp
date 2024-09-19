#include <iostream>

template <typename T, typename U>
auto mult(T a, U b) {
	return a * b;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}
