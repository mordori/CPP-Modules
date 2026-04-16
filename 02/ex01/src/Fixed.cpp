#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed()
{ std::cout << "Default constructor called" << '\n'; }

Fixed::Fixed(const int value) :
	m_rawBits{ value << FRAC_BITS }
{ std::cout << "Int constructor called" << '\n'; }

Fixed::Fixed(const float value) :
	m_rawBits{ static_cast<int>(roundf(value * (1 << FRAC_BITS))) }
{ std::cout << "Float constructor called" << '\n'; }

Fixed::~Fixed()
{ std::cout << "Destructor called" << '\n'; }

Fixed::Fixed(const Fixed& other) :
	m_rawBits{ other.m_rawBits }
{ std::cout << "Copy constructor called" << '\n'; }

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this == &other)
		return *this;
	m_rawBits = other.m_rawBits;
	return *this;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(m_rawBits) / (1 << FRAC_BITS));
}

int Fixed::toInt() const
{
	return (m_rawBits >> FRAC_BITS);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << '\n';
	return m_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << '\n';
	m_rawBits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
