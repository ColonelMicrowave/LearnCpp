#include <iostream>
#include <string_view>
#include <string>
#include <array>
#include <limits>
#include "random.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c)
{
	return c - '0';
}

namespace Potion
{
	enum Type
	{
		healing,
		mana,
		speed,
		invisibility,
		max_potions
	};

	constexpr std::array<Type, max_potions> types{ healing, mana, speed, invisibility };
	constexpr std::array<int, max_potions> costs{ 20, 30, 12, 50 };
	constexpr std::array<std::string_view, max_potions> names{ "healing", "mana", "speed", "invisibility" };
}

class Player
{
private:
	static constexpr int s_minStartingGold{ 80 };
	static constexpr int s_maxStartingGold{ 120 };

	std::string m_name{};
	std::array<int, Potion::max_potions> m_inventory{};
	int m_gold{};

public:
	explicit Player(std::string_view name) :
		m_name{ name },
		m_gold{ Random::get(s_minStartingGold, s_maxStartingGold) }
	{
	}

	int getGold() const                    { return m_gold; }
	int getInventory(Potion::Type t) const { return m_inventory[t]; }

	void setGold(int gold) { m_gold = gold; }
	void setInventory(Potion::Type t) { m_inventory[t] += 1; }
};

Potion::Type purchasePotion()
{
	std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

	while (true)
	{
		char choice{};
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Try again: ";

			continue;
		}

		ignoreLine();

		if (choice == 'q')
		{
			return Potion::max_potions;
		}

		choice = charNumToInt(choice);

		if (choice < 0 || choice > 4)
		{
			std::cout << "Invalid input. Try again: ";
			continue;
		}

		return static_cast<Potion::Type>(choice);
	}
}

void shop(Player& user)
{
	while (true)
	{
		std::cout << "Here is our selection for today:\n";

		for (auto t : Potion::types)
		{
			std::cout << t << ") " << Potion::names[t] << " costs " << Potion::costs[t] << '\n';
		}

		Potion::Type choice{ purchasePotion() };

		if (choice == Potion::max_potions)
		{
			break;
		}

		if (Potion::costs[choice] > user.getGold())
		{
			std::cout << "You can not afford that.\n\n";
			continue;
		}

		user.setGold(user.getGold() - Potion::costs[choice]);
		user.setInventory(choice);

		std::cout << "You purchased a potion of " << Potion::names[choice] << ". You have " << user.getGold() << " gold left.\n\n";
	}

	std::cout << "\nYour inventory contains:\n";
	for (const auto& t : Potion::types)
	{
		if (user.getInventory(t) == 0)
		{
			continue;
		}
		else
		{
			std::cout << user.getInventory(t) << "x potion of " << Potion::names[t] << '\n';
		}
	}
	std::cout << "You escaped with " << user.getGold() << " gold.\n";
}

int main()
{
	std::cout << "Welcome to Roscoe's Potion Emporium!\n";

	std::cout << "Enter your name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	Player user{ name };

	std::cout << "Hello, " << name << ", you have " << user.getGold() << " gold.\n\n";

	shop(user);

	std::cout << "\nThanks for shopping at Roscoe's Potion Emporium!\n";

	return 0;
}
