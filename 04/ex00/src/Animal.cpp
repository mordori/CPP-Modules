#include "Animal.hpp"

#include <iostream>

Animal::Animal()
{ std::cout << "\033[1;34mAnimal::Constructor\033[0m\n"; }

Animal::Animal(const Animal &other) : type{other.type}
{ std::cout << "\033[1;34mAnimal::Copy Constructor\033[0m\n"; }

Animal::~Animal()
{ std::cout << "\033[1;34mAnimal::Destructor\033[0m\n"; }
