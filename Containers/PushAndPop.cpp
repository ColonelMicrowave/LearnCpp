#include <iostream>
#include <vector>

void printStack(const std::vector<int>& arr)
{
	std::cout << "\t(Stack:";
	for (auto i : arr)
		std::cout << " " << i;

	if (arr.empty())
		std::cout << " empty";

	std::cout << ")\n";
}

void pushAndPrint(std::vector<int>& arr, int value)
{
	arr.push_back(value);
	std::cout << "Push " << value;
	printStack(arr);
}

void popAndPrint(std::vector<int>& arr)
{
	std::cout << "Pop ";
	arr.pop_back();
	printStack(arr);
}

int main()
{
	std::vector<int> arr{};

	printStack(arr);

	pushAndPrint(arr, 1);
	pushAndPrint(arr, 2);
	pushAndPrint(arr, 3);
	popAndPrint(arr);
	pushAndPrint(arr, 4);
	popAndPrint(arr);
	popAndPrint(arr);
	popAndPrint(arr);

	return 0;
}
