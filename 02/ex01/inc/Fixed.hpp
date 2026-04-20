#pragma once

#include <iosfwd>

class Fixed
{
private:
	static constexpr int FRAC_BITS{ 8 };
	int m_bits{};

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

	float toFloat() const;
	int toInt() const;
	int getRawBits() const;
	void setRawBits(int const raw);

	Fixed& operator=(const Fixed& other);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
