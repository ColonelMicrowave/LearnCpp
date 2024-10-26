#include <iostream>
#include <vector>
#include <string>
#include <cassert>

namespace Items
{
	enum Type: int
	{
		healthPotion, // 0
		torch, // 1
		arrow, // 2
		maxItems // 3
	};
}

std::string_view getItemNamePlural(Items::Type type)
{
	switch (type)
	{
	case Items::healthPotion:  return "health potions";
	case Items::torch:         return "torches";
	case Items::arrow:         return "arrows";

	default:                   return "???";
	}
}

std::string_view getItemNameSingular(Items::Type type)
{
	switch (type)
	{
	case Items::healthPotion:  return "health potion";
	case Items::torch:         return "torch";
	case Items::arrow:         return "arrow";

	default:                   return "???";
	}
}

template <typename T>
constexpr std::size_t toUZ(T value)
{
	static_assert(std::is_integral<T>() || std::is_enum<T>());

	return static_cast<std::size_t>(value);
}

void printEachItem(const std::vector<int>& inventory, Items::Type type)
{
	bool plural{ inventory[toUZ(type)] != 1 };
	std::cout << "You have " << inventory[toUZ(type)] << " ";
	std::cout << (plural ? getItemNamePlural(type) : getItemNameSingular(type)) << ".\n";
}

void printTotalItems(const std::vector<int>& inventory)
{
	int total{ 0 };
	for (auto i : inventory)
	{
		total += i;
	}

	std::cout << "Total items: " << total << "\n";
}

int main()
{
	std::vector inventory{ 1, 5, 10 };
	assert(inventory.size() == Items::maxItems);

	for (int i{ 0 }; i < Items::maxItems; ++i)
	{
		auto item{ static_cast<Items::Type>(i) };
		printEachItem(inventory, item);
	}

	printTotalItems(inventory);

	return 0;
}
