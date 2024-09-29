#include <iostream>
#include <string>

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
	switch (animal)
	{
	case Animal::pig:     return "pig";
	case Animal::chicken: return "chicken";
	case Animal::goat:    return "goat";
	case Animal::cat:     return "cat";
	case Animal::dog:     return "dog";
	case Animal::duck:    return "duck";
	default:              return "unknown";
	}
}

void printNumberOfLegs(Animal animal)
{
	std::cout << "A " << getAnimalName(animal) << " has ";

	switch (animal)
	{
	case Animal::chicken:
	case Animal::duck:
		std::cout << 2;
		break;

	case Animal::pig:
	case Animal::goat:
	case Animal::cat:
	case Animal::dog:
		std::cout << 4;
		break;

	default:
		std::cout << "an unknown number of";
		break;
	}

	std::cout << " legs.\n";
}

int main()
{
	printNumberOfLegs(Animal::cat);
	printNumberOfLegs(Animal::chicken);
}
