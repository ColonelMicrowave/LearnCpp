#include <iostream>
#include <limits>
#include <optional>
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

// Teach the compiler how to print an Animal
std::ostream& operator<<(std::ostream& out, Animal animal)
{
	out << getAnimalName(animal);
	return out;
}

void printNumberOfLegs(Animal animal)
{
	std::cout << "A " << animal << " has ";

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

constexpr std::optional<Animal> getUserInput(std::string_view sv)
{
	if (sv == "pig")     return Animal::pig;
	if (sv == "chicken") return Animal::chicken;
	if (sv == "goat")    return Animal::goat;
	if (sv == "cat")     return Animal::cat;
	if (sv == "dog")     return Animal::dog;
	if (sv == "duck")    return Animal::duck;

	return {}; // invalid input
}

// Teach the compiler how to read an Animal
std::istream& operator>>(std::istream& in, Animal& animal)
{
	std::string s{};
	in >> s;

	std::optional<Animal> match{ getUserInput(s) };
	if (match)
	{
		animal = *match;
		return in;
	}

	in.setstate(std::ios_base::failbit); // set the stream state to fail

	return in;
}

int main()
{
	while (true)
	{
		std::cout << "This program can tell you how many legs a pig, chicken, goat, cat, dog, or duck has.\n";
		std::cout << "Please choose from this selection: ";
		Animal animal{};
		std::cin >> animal;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. This program only allows lowercase inputs. Please try again.\n";
		}
		else
		{
			printNumberOfLegs(animal);
			return 0;
		}
	}
}
