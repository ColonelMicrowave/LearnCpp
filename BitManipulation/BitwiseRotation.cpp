#include <bitset>
#include <iostream>


std::bitset<4> rotateLeft(std::bitset<4> bits)
{
	std::bitset<4> shiftedBits{ bits << 1 };
	std::bitset<4> rotatedBits{ shiftedBits | (bits >> 3) };

	return rotatedBits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotateLeft(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotateLeft(bits2) << '\n';

	return 0;
}
