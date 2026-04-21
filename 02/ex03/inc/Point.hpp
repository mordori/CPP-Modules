#pragma once

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x{};
	const Fixed y{};
public:
	Point() = default;
	Point(const float xx, const float yy);
	Point(const Point& other);
	~Point() = default;

	const Fixed& getX() const;
	const Fixed& getY() const;
	static Fixed cross(const Point& a, const Point& b, const Point& c);

	Point& operator=(const Point& other);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
