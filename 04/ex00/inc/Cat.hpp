#pragma once

#include "Animal.hpp"

#include <string>

class Cat : public Animal
{
private:

public:
	Cat();
	Cat(const Animal& other);
	~Animal();

	Cat& operator=(const Cat& other) = default;
};
