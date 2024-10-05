#include <iostream>

// Class template
template <typename T>
struct Triad
{
	T first{};
	T second{};
	T third{};
};

// Deduction guide
// This guide is used by the compiler to deduce the type of the template arguments
template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& triad)
{
	std::cout << triad.first << ", " << triad.second << ", " << triad.third << '\n';
}

int main()
{
	Triad t1{ 1, 2, 3 };
	print(t1);

	Triad t2{ 1.1, 2.2, 3.3 };
	print(t2);

	return 0;
}
