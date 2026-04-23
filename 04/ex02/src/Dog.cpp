#include "Dog.hpp"

#include <iostream>

#include "Brain.hpp"

Dog::Dog() :
	Animal{ "Dog" }
{
	std::cout << "\033[1;34mDog::Constructor\033[0m\n";
	m_brain = new Brain();
}

Dog::Dog(const Dog& other) :
	Animal{ other }
{
	std::cout << "\033[1;34mDog::Copy Constructor\033[0m\n";
	m_brain = new Brain(*other.m_brain);
}

Dog::~Dog()
{
	std::cout << "\033[1;31mDog::Destructor\033[0m\n";
	delete m_brain;
}

void Dog::makeSound() const
{ std::cout << "Woof!\n"; }

Brain& Dog::getBrain()
{ return *m_brain; }

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	Brain* temp = new Brain(*other.m_brain);
	delete m_brain;
	m_brain = temp;
	return *this;
}
