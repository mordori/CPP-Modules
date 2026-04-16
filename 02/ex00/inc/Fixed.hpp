#pragma once

class Fixed
{
private:
	static const int FRAC_BITS{ 8 };
	int m_rawBits{};

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	int getRawBits() const;
	void setRawBits(int const raw);
};
