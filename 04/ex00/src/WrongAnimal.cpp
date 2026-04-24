#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal()
{ std::cout << "\033[1;34mWrongAnimal::Constructor\033[0m\n"; }

WrongAnimal::WrongAnimal(const std::string& type_) :
	type { type_ }
{ std::cout << "\033[1;34mWrongAnimal::Constructor\033[0m\n"; }

WrongAnimal::WrongAnimal(const WrongAnimal &other) :
	type{other.type}
{ std::cout << "\033[1;34mWrongAnimal::Copy Constructor\033[0m\n"; }

WrongAnimal::~WrongAnimal()
{ std::cout << "\033[1;31mWrongAnimal::Destructor\033[0m\n"; }

void WrongAnimal::makeSound() const
{ std::cout << "Default WrongAnimal sound!\n"; }

const std::string& WrongAnimal::getType() const
{ return type; }

