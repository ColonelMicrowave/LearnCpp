#include <iostream>
#include <string>

class Ball
{
private:
	std::string m_colour{};
	double m_radius{};

public:
	Ball(std::string_view colour, double radius)
		: m_colour{ colour }
		, m_radius{ radius }
	{
	}

	const std::string& getColour() const { return m_colour; }
	double getRadius() const { return m_radius; }
};

void print(Ball ball)
{
	std::cout << "Ball(" << ball.getColour() << ", " << ball.getRadius() << ")\n";
}

int main()
{
	Ball blue{ "blue", 10.0 };
	print(blue);

	Ball red{ "red", 12.0 };
	print(red);

	return 0;
}
