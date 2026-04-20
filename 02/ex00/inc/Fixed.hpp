#pragma once

class Fixed
{
private:
	static constexpr int FRAC_BITS{ 8 };
	int m_bits{};

public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

	Fixed& operator=(const Fixed& other);
};
