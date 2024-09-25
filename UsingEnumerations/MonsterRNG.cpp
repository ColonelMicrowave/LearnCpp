#include <iostream>
#include <limits>
#include <string>
#include "random.h"

namespace Monster
{
	enum MonsterType
	{
		orc,
		goblin,
		troll,
		ogre,
		skeleton,
		maxMonsters,
	};
}

std::string_view getMonster(Monster::MonsterType type)
{
	switch (type)
	{
	case Monster::orc:
		return "An Orc appeared\n";
	case Monster::goblin:
		return "A Goblin appeared\n";
	case Monster::troll:
		return "A Troll appeared\n";
	case Monster::ogre:
		return "An Ogre appeared\n";
	case Monster::skeleton:
		return "A Skeleton appeared\n";
	default:
		return "You've broken the time loop\n";
	}
}

int main()
{
	while (true)
	{
		std::cout << "You enter the forest...\n" << "Enter 1 to continue further\n";
		int choice{};
		std::cin >> choice;

		// Input validation
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.\n";
		}
		else if (choice == 1)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.\n";
		}
	}

	// Generates a random monster by choosing a random number and casting it to a MonsterType
	Monster::MonsterType randomMonster{ static_cast<Monster::MonsterType>(Random::get(0, static_cast<int>(Monster::maxMonsters))) };
	std::cout << getMonster(randomMonster);

	return 0;
}
