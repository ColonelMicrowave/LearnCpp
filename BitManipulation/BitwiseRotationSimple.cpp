#include <bitset>
#include <iostream>

std::bitset<4> rotateLeft(std::bitset<4> bits)
{
	const bool bitCheck = bits.test(3);

	bits <<= 1;

	if (bitCheck)
		bits.set(0);

	return bits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotateLeft(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotateLeft(bits2) << '\n';

	return 0;
}
