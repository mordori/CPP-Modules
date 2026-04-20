#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed() :
	m_bits{ 0 }
{ std::cout << "Default constructor called" << '\n'; }

Fixed::Fixed(const int value) :
	m_bits{ value << FRAC_BITS }
{ std::cout << "Int constructor called" << '\n'; }

Fixed::Fixed(const float value) :
	m_bits{ static_cast<int>(roundf(value * (1 << FRAC_BITS))) }
{ std::cout << "Float constructor called" << '\n'; }

Fixed::Fixed(const Fixed& other) :
	m_bits{ other.m_bits }
{ std::cout << "Copy constructor called" << '\n'; }

Fixed::~Fixed()
{ std::cout << "Destructor called" << '\n'; }

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
	std::cout << "getRawBits member function called" << '\n';
	return m_bits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << '\n';
	m_bits = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this == &other)
		return *this;
	m_bits = other.m_bits;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return os << fixed.toFloat();
}
