#pragma once

#include <iostream>

class Conversions
{
private:
	Conversions(const Conversions& other) = delete;
	Conversions& operator=(const Conversions& other) = delete;

public:
	template <typename T>
	Conversions(T value)
	{

	}
	~Conversions() = default;
};
