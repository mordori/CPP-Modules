#include "Dog.hpp"

#include <iostream>

Dog::Dog() :
	Animal{ "Dog" }
{ std::cout << "\033[1;34mDog::Constructor\033[0m\n"; }

Dog::Dog(const Dog& other) :
	Animal{ other }
{ std::cout << "\033[1;34mDog::Copy Constructor\033[0m\n"; }

Dog::~Dog()
{ std::cout << "\033[1;31mDog::Destructor\033[0m\n"; }

void Dog::makeSound() const
{ std::cout << "Woof!\n"; }
