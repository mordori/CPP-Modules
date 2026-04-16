#pragma once

#include <iosfwd>

class Fixed
{
private:
	static const int FRAC_BITS{ 8 };
	int m_rawBits{};

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	float toFloat() const;
	int toInt() const;
	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
