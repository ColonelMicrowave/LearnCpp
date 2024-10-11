#include <iostream>
#include <string>

class Ball
{
private:
	std::string m_colour{ "Black" };
	double m_radius{ 10.0 };

public:
	// Constructor with default values for colour and radius if not provided by caller
	Ball(std::string_view colour = "Black", double radius = 10.0)
		: m_colour{ colour }
		, m_radius{ radius }
	{
		print();
	}

	// Constructor which takes radius and delegates to the other constructor
	Ball(double radius)
		: Ball{ "Black", radius }
	{
	}

	void print() const
	{
		std::cout << "Ball(" << m_colour << ", " << m_radius << ")\n";
	}
};

int main()
{
	Ball def{};
	Ball blue{ "Blue" };
	Ball twenty{ 20.0 };
	Ball redTwenty{ "Red", 20.0 };

	return 0;
}
