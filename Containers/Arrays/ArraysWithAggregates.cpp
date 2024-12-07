#include <iostream>
#include <array>

struct Item
{
	std::string_view name{};
	int gold{};
};

template <std::size_t N>
void printArray(const std::array<Item, N>& arr)
{
	for (const auto& item : arr)
	{
		std::cout << "A " << item.name <<
			" costs " << item.gold << " gold.\n";
	}
}

int main()
{
	constexpr std::array<Item, 4> item 
	{{
		{ "sword",  5 },
		{ "dagger", 3 },
		{ "club",   2 },
		{ "spear",  7 }
	}};

	printArray(item);

	return 0;
}
