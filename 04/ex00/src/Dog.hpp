#pragma once

#include <string>

#include "Animal.hpp"

class Dog : public Animal {
private:
public:
	Dog();
	Dog(const Dog& other);
	~Dog() override;

	void makeSound() const override;

	Dog& operator=(const Dog& other) = default;
};
