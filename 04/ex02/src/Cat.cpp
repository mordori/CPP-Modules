#include "Cat.hpp"

#include <iostream>

#include "Brain.hpp"

Cat::Cat() :
	Animal{ "Cat" }
{
	std::cout << "\033[1;34mCat::Constructor\033[0m\n";
	m_brain = new Brain();
}

Cat::Cat(const Cat& other) :
	Animal{ other }
{
	std::cout << "\033[1;34mCat::Copy Constructor\033[0m\n";
	m_brain = new Brain(*other.m_brain);
}

Cat::~Cat()
{
	std::cout << "\033[1;31mCat::Destructor\033[0m\n";
	delete m_brain;
}

void Cat::makeSound() const
{ std::cout << "Meow!\n"; }

Brain& Cat::getBrain()
{ return *m_brain; }

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	Brain* temp = new Brain(*other.m_brain);
	delete m_brain;
	m_brain = temp;
	return *this;
}
