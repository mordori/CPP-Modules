#include "Cat.hpp"

#include <iostream>

Cat::Cat() :
	Animal{ "Cat" }
{ std::cout << "\033[1;34mCat::Constructor\033[0m\n"; }

Cat::Cat(const Cat& other) :
	Animal{ other }
{ std::cout << "\033[1;34mCat::Copy Constructor\033[0m\n"; }

Cat::~Cat()
{ std::cout << "\033[1;31mCat::Destructor\033[0m\n"; }

void Cat::makeSound() const
{ std::cout << "Meow!\n"; }
