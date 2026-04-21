#include "Fixed.hpp"

#include <iostream>
#include <cmath>

#pragma region Constructors

Fixed::Fixed(const int value) :
	m_bits{ value << FRAC_BITS }
{}

Fixed::Fixed(const float value) :
	m_bits{ static_cast<int>(roundf(value * (1 << FRAC_BITS))) }
{}

Fixed::Fixed(const Fixed& other) :
	m_bits{ other.m_bits }
{}

#pragma endregion

#pragma region Member Functions

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
	return m_bits;
}

void Fixed::setRawBits(int const raw)
{
	m_bits = raw;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

#pragma endregion

#pragma region Operators

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return *this;
	m_bits = other.m_bits;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return os << fixed.toFloat();
}

#pragma region Comparisons

bool Fixed::operator>(const Fixed& rhs) const
{
	return  m_bits > rhs.m_bits;
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return  m_bits < rhs.m_bits;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return  m_bits >= rhs.m_bits;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return  m_bits <= rhs.m_bits;
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return  m_bits == rhs.m_bits;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return  m_bits != rhs.m_bits;
}

#pragma endregion

#pragma region Arithmetics

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed result{};
	result.m_bits = m_bits + rhs.m_bits;
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed result{};
	result.m_bits = m_bits - rhs.m_bits;
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed result{};
	long long temp = (static_cast<long long>(m_bits) * rhs.m_bits) >> FRAC_BITS;
	result.m_bits = static_cast<int>(temp);
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed result{};
	long long temp = (static_cast<long long>(m_bits) << FRAC_BITS) / rhs.m_bits;
	result.m_bits = static_cast<int>(temp);
	return result;
}

#pragma endregion

#pragma region Increment/Decrement

Fixed& Fixed::operator++()
{
	++m_bits;
	return *this;
}

Fixed& Fixed::operator--()
{
	--m_bits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp{ *this };
	++m_bits;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp{ *this };
	--m_bits;
	return temp;
}

#pragma endregion

#pragma endregion
