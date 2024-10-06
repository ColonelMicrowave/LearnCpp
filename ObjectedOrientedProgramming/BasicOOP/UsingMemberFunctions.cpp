#include <iostream>

struct IntPair
{
	int num1{};
	int num2{};

	void print()
	{
		std::cout << "Pair (" << num1 << ", " << num2 << ")\n";
	}

	bool isEqual(IntPair p2)
	{
		return ((num1 == p2.num1) && (num2 == p2.num2));
	}
};

int main()
{
	IntPair p1{ 1, 2 };
	IntPair p2{ 3, 4 };

	std::cout << "Pair 1: ";
	p1.print();

	std::cout << "Pair 2: ";
	p2.print();

	std::cout << "Pair 1 and Pair 1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "Pair 1 and Pair 2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}
