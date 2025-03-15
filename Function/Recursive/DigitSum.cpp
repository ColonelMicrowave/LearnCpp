#include <iostream>

int digitSum(int num)
{
	if (num < 10)
		return num;

	return digitSum(num / 10) + (num % 10);
}

int main()
{
	std::cout << digitSum(93427) << '\n';

	return 0;
}
