#pragma once

#include "Animal.hpp"

#include <string>

class Dog : public Animal
{
private:

public:
	Dog();
	Dog(const Dog& other);
	~Dog() override;

	void makeSound() const override;

	Dog& operator=(const Dog& other) = default;
};
