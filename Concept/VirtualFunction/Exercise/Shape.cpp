#include <iostream>
#include <vector>

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p) 
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Shape
{
public:

	virtual std::ostream& print(std::ostream &out) const = 0;

	friend std::ostream& operator<<(std::ostream &out, const Shape &shape)
	{
		return shape.print(out);
	}

	virtual ~Shape() {}
};

class Triangle : public Shape
{
private:
	Point m_1;
	Point m_2;
	Point m_3;

public:
	Triangle(const Point &p1, const Point &p2, const Point &p3)
		: m_1(p1), m_2(p2), m_3(p3)
	{
	}

	virtual std::ostream& print(std::ostream &out) const override {
		out << "Triangle(" << m_1 << ", " << m_2 << ", " << m_3 << ")";
		return out;
	}
};

class Circle : public Shape
{
private:
	Point m_center;
	int m_radius;

public:
	Circle(const Point &center, int radius) :
		m_center(center), m_radius(radius)
	{}

	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Circle(" << m_center << ", radius " << m_radius << ")";
		return out;
	}

	int getRadius() { return m_radius; }
};

int getLargestRadius(std::vector<Shape*> &v)
{
	int max = 0;
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		Circle *c = dynamic_cast<Circle*>(v[i]);

		if (!c)
			continue;

		if (c->getRadius() > max)
			max = c->getRadius();
	}

	return max;
}

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	for (unsigned int i = 0; i < v.size(); ++i)
		std::cout << *(v[i]) << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

	for (unsigned int i = 0; i < v.size(); ++i)
		delete v[i];

	return 0;
}
