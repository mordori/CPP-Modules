#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() :
	WrongAnimal{ "WrongCat" }
{ std::cout << "\033[1;34mWrongCat::Constructor\033[0m\n"; }

WrongCat::WrongCat(const WrongCat& other) :
	WrongAnimal{ other }
{ std::cout << "\033[1;34mWrongCat::Copy Constructor\033[0m\n"; }

WrongCat::~WrongCat()
{ std::cout << "\033[1;31mWrongCat::Destructor\033[0m\n"; }

void WrongCat::makeSound() const
{ std::cout << "WrongMeow!\n"; }
