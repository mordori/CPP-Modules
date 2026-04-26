#pragma once

#include "Animal.hpp"

#include <string>

class Brain;

class Dog : public Animal
{
private:
	Brain* m_brain{};

public:
	Dog();
	Dog(const Dog& other);
	~Dog() override;

	Brain& getBrain();

	void makeSound() const override;

	Dog& operator=(const Dog& other);
};
