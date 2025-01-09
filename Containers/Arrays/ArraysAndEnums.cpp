#include <iostream>
#include <array>
#include <limits>
#include <string>
#include <string_view>

// Helper functions
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace Animal
{
	enum Type
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals
	};

	struct Data
	{
		std::string_view name{};
		int leg{};
		std::string_view sound{};
	};

	std::array<Data, max_animals> animals
	{ {
		{"chicken",  2, "cluck"},
		{"dog",      4, "bark"},
		{"cat",      4, "meow"},
		{"elephant", 4, "pawoo"},
		{"duck",     2, "quack"},
		{"snake",    0, "hiss"}
	} };

	static_assert(std::size(animals) == max_animals); // Make sure array has all the enumerators in it
}

std::istream& operator>> (std::istream& in, Animal::Type& animal)
{
	std::string input{};
	std::getline(in >> std::ws, input);

	for (std::size_t index{ 0 }; index < Animal::animals.size(); ++index)
	{
		if (input == Animal::animals[index].name)
		{
			animal = static_cast<Animal::Type>(index);
			return in;
		}
	}

	in.setstate(std::ios_base::failbit); // Invalid input
	animal = {};

	return in;
}

Animal::Type getUserInput()
{
	while (true)
	{
		std::cout << "Enter an animal: ";
		Animal::Type name{};
		std::cin >> name;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input. Does not match name of our animals.\n";

			continue;
		}

		return name;
	}
}

void printStats(Animal::Type uChoice)
{
	using namespace Animal;

	std::cout << "A " << animals[uChoice].name 
		<< " has " << animals[uChoice].leg 
		<< " legs and says " << animals[uChoice].sound << ".\n\n";

	std::cout << "Here is the data for the rest of the animals: \n";

	for (const auto& a : animals)
	{
		if (a.name == animals[uChoice].name)
		{
			continue;
		}
		else
		{
			std::cout << "A " << a.name << " has " << a.leg << " legs and says " << a.sound << ".\n";
		}
	}
}

int main()
{
	Animal::Type animal{ getUserInput() };
	printStats(animal);

	return 0;
}
