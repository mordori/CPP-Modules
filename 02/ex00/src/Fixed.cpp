#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
{ std::cout << "Default constructor called" << '\n'; }

Fixed::~Fixed()
{ std::cout << "Destructor called" << '\n'; }

Fixed::Fixed(const Fixed& other) : m_rawBits{ other.m_rawBits }
{ std::cout << "Copy constructor called" << '\n'; }

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this == &other)
		return *this;
	m_rawBits = other.m_rawBits;
	return *this;
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
