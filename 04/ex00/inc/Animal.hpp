#pragma once

#include <string>

class Animal
{
private:

protected:
	std::string type{};

public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();

	Animal& operator=(const Animal& other) = default;
};
