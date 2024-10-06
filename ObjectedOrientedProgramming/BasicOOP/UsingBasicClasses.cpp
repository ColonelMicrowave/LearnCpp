#include <iostream>

class Point3d
{
private:
	int m_x{};
	int m_y{};
	int m_z{};

public:
	void setValues(int x, int y, int z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print() const
	{
		std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
	}

	bool isEqual(const Point3d& p) const
	{
		return ((m_x == p.m_x) && (m_y == p.m_y) && (m_z == p.m_z));
	}
};

int main()
{
	Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	point1.print();

	std::cout << "point1 and point2 are " << (point1.isEqual(point2) ? "" : "not ") << "equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point1 and point3 are " << (point1.isEqual(point3) ? "" : "not ") << "equal\n";

	return 0;
}
