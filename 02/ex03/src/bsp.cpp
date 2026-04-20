#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Fixed minX{ Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX()) };
	const Fixed minY{ Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY()) };
	const Fixed maxX{ Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX()) };
	const Fixed maxY{ Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY()) };
	if (point.getX() < minX || point.getX() > maxX)
		return false;
	if (point.getY() < minY || point.getY() > maxY)
		return false;
	Fixed c1 = Point::cross(a, b, point);
	Fixed c2 = Point::cross(b, c, point);
	Fixed c3 = Point::cross(c, a, point);
	bool isInsideCCW{ (c1 > 0) && (c2 > 0) && (c3 > 0) };
	bool isInsideCW{ (c1 < 0) && (c2 < 0) && (c3 < 0) };
	return isInsideCCW || isInsideCW;
}
