#include <iostream>

template <typename T, typename U>
auto add(T x, U y)
{
	return x + y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';
	std::cout << add(1.2, 3) << '\n';

	return 0;
}
