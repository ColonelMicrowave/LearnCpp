#include <iostream>
#include <string_view>

struct Monster
{

	enum Type
	{
		Ogre,
		Dragon,
		Orc,
		GiantSpider,
		Slime,
	};

	Type type{};
	std::string_view name{};
	int health{};
};

constexpr std::string_view getMonsterTypeString(Monster::Type type)
{
	switch (type)
	{
	case Monster::Ogre:        return "Ogre";
	case Monster::Dragon:      return "Dragon";
	case Monster::Orc:         return "Orc";
	case Monster::GiantSpider: return "Giant Spider";
	case Monster::Slime:       return "Slime";
	}

	return "Unknown";
}

void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) << 
		" is named " << monster.name << 
		" and has " << monster.health << " health.\n";
}

int main()
{
	Monster torg{ Monster::Ogre, "Torg", 145 };
	Monster blurp{ Monster::Slime, "Blurp", 23 };

	printMonster(torg);
	printMonster(blurp);

	return 0;
}
