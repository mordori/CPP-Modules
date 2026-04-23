#pragma once

#include "Animal.hpp"

#include <string>

#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* m_brain{};

public:
	Cat();
	Cat(const Cat& other);
	~Cat() override;

	Brain& getBrain();

	void makeSound() const override;

	Cat& operator=(const Cat& other);
};
