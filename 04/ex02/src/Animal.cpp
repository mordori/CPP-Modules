#include "Animal.hpp"

#include <iostream>

Animal::Animal()
{ std::cout << "\033[1;34mAnimal::Constructor\033[0m\n"; }

Animal::Animal(const std::string& type_) :
	type { type_ }
{ std::cout << "\033[1;34mAnimal::Constructor\033[0m\n"; }

Animal::Animal(const Animal &other) :
	type{other.type}
{ std::cout << "\033[1;34mAnimal::Copy Constructor\033[0m\n"; }

Animal::~Animal()
{ std::cout << "\033[1;31mAnimal::Destructor\033[0m\n"; }

void Animal::makeSound() const
{ std::cout << "Default Animal sound!\n"; }

const std::string& Animal::getType() const
{ return type; }
