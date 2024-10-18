#include <iostream>
#include <string>
#include "random.h"

class Monster
{
public:
	enum Type
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		maxMonsterTypes,
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

public:
	Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
		: m_type{ type }
		, m_name{ name }
		, m_roar{ roar }
		, m_hitPoints{ hitPoints }
	{
	}

	constexpr std::string_view getTypeString(Monster::Type type) const
	{
		switch (type)
		{
		case Monster::Dragon:	return "dragon";
		case Monster::Goblin:	return "goblin";
		case Monster::Ogre:		return "ogre";
		case Monster::Orc:		return "orc";
		case Monster::Skeleton: return "skeleton";
		case Monster::Troll:	return "troll";
		case Monster::Vampire:	return "vampire";
		case Monster::Zombie:	return "zombie";
		default:				return "???";
		}
	}

	void print() const
	{
		if (m_hitPoints == 0)
			std::cout << m_name << " the " << getTypeString(m_type) << " is dead\n";
		else
			std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
	}
};

namespace MonsterGenerator
{
	std::string_view getName(int num)
	{
		switch (num)
		{
		case 0:  return "Athos";
		case 1:  return "Blarg";
		case 2:  return "Moog";
		case 3:  return "Pksh";
		case 4:  return "Tyrn";
		case 5:	 return "Mort";
		default: return "???";
		}
	}

	std::string_view getRoar(int num)
	{
		switch (num)
		{
		case 0:  return "*ROAR*";
		case 1:  return "*peep*";
		case 2:  return "*squeal*";
		case 3:  return "*whine*";
		case 4:  return "*hum*";
		case 5:	 return "*burp*";
		default: return "???";
		}
	}

	Monster generate()
	{
		return Monster{ static_cast<Monster::Type>(Random::get(0, (Monster::maxMonsterTypes - 1)))
			, getName(Random::get(0, 5))
			, getRoar(Random::get(0, 5))
			, Random::get(0, 100)
		};
	}
}

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
