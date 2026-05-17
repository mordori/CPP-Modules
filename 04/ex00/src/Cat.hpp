#pragma once

#include <string>

#include "Animal.hpp"

class Cat : public Animal {
private:
public:
	Cat();
	Cat(const Cat& other);
	~Cat() override;

	void makeSound() const override;

	Cat& operator=(const Cat& other) = default;
};
