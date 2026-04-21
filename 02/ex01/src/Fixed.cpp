#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed()
{ std::cout << "Fixed::Constructor" << '\n'; }

Fixed::Fixed(const int value) :
	m_bits{ value << FRAC_BITS }
{ std::cout << "Fixed::Constructor(int)" << '\n'; }

Fixed::Fixed(const float value) :
	m_bits{ static_cast<int>(roundf(value * (1 << FRAC_BITS))) }
{ std::cout << "Fixed::Constructor(float)" << '\n'; }

Fixed::Fixed(const Fixed& other) :
	m_bits{ other.m_bits }
{ std::cout << "Fixed::Copy Constructor" << '\n'; }

Fixed::~Fixed()
{ std::cout << "Fixed::Destructor" << '\n'; }

float Fixed::toFloat() const
{
	return static_cast<float>(m_bits) / (1 << FRAC_BITS);
}

int Fixed::toInt() const
{
	return m_bits >> FRAC_BITS;
}

int Fixed::getRawBits() const
{
	std::cout << "Fixed::getRawBits" << '\n';
	return m_bits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "Fixed::setRawBits" << '\n';
	m_bits = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Fixed::Copy Assignment" << '\n';
	m_bits = other.m_bits;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return os << fixed.toFloat();
}
