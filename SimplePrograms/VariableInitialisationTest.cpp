#include <iostream>

int main()
{
	int a = 5;
	int b( 5 );
	int c{ 5 };
	int d = { 5 };
	std::cout << "The value for A is: " << a << std::endl;
	std::cout << "The value for B is: " << b << std::endl;
	std::cout << "The value for C is: " << c << std::endl;
	std::cout << "The value for D is: " << d << std::endl;

	return 0;
}
