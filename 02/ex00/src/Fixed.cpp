#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
{ std::cout << "Fixed::Constructor" << '\n'; }

Fixed::Fixed(const Fixed& other) :
	m_bits{ other.m_bits }
{ std::cout << "Fixed::Copy Constructor" << '\n'; }

Fixed::~Fixed()
{ std::cout << "Fixed::Destructor" << '\n'; }

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
