#include <iostream>
#include <vector>
#include <cassert>

namespace Animal
{
	enum Type
	{
		chicken, // 0
		dog, // 1
		cat, // 2
		elephant, // 3
		duck, // 4
		snake, // 5
		max_animals // 6
	};

	std::vector<int> legs{ 2, 4, 4, 4, 2, 0 };
}

int main()
{
	assert((std::size(Animal::legs) == Animal::max_animals) && ("Size mismatch between animals and array"));

	std::cout << "An elephant has " << Animal::legs[Animal::elephant] << " legs.\n";

	return 0;
}
