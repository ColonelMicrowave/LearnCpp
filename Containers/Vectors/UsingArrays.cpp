#include <iostream>
#include <vector>

int main()
{
	std::vector hello{ 'h', 'e', 'l', 'l', 'o' };
	std::cout << "The array has " << std::size(hello) << " elements\n";
	std::cout << hello.at(1) << hello[1] << '\n';

	return 0;
}
