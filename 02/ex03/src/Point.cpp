#include "Point.hpp"

Point::Point(const float xx, const float yy) :
	x{ xx }, y{ yy }
{}

Point::Point(const Point& other) :
	x{ other.x }, y{ other.y }
{}

const Fixed& Point::getX() const
{ return x; }

const Fixed& Point::getY() const
{ return y; }

Fixed Point::cross(const Point& a, const Point& b, const Point& c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}
