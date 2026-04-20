#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

void test(Point const a, Point const b, Point const c, Point const p);

int main()
{
	Point a{ 1.0f, 1.0f };
	Point b{ 3.0f, 1.0f };
	Point c{ 2.0f, 3.0f };

	// Inside
	{
		Point p{ 2.2f, 2.1f };
		test(a, b, c, p);
	}

	// Outside
	{
		Point p{ 6.2f, 2.1f };
		test(a, b, c, p);
	}

	// On point A
	{
		Point p{ 1.0f, 1.0f };
		test(a, b, c, p);
	}

	// On edge A->B
	{
		Point p{ 2.0f, 1.0f };
		test(a, b, c, p);
	}

	return 0;
}

void test(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << (bsp(a, b, c, p) ? "inside" : "outside") << '\n';
}
