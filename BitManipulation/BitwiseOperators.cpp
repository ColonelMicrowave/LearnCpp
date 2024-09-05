#include <bitset>
#include <iostream>

int main()
{
	std::bitset<4> x{ 0b1100 };

	//Bit Shifting
	std::cout << "Original bits: " << x << '\n';
	std::cout << "Bit shift to the right: " << (x >> 1) << '\n';
	std::cout << "Bit shift to the left: " << (x << 1) << '\n';

	//Bitwise NOT
	std::cout << "Bitwise NOT (1100): " << ~x << '\n';

	//Bitwise OR
	std::cout << "Bitwise OR (0101 and 0110): " << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';

	//Bitwise AND
	std::cout << "Bitwise AND (0101 and 0110): " << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n';

	//Bitwise XOR
	std::cout << "Bitwise XOR (0101 and 0110): " << (std::bitset<4>{ 0b0101 }^ std::bitset<4>{ 0b0110 }) << '\n';

	return 0;
}
