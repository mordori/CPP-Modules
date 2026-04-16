#include "Zombie.hpp"

#include <string>
#include <iostream>

Zombie::Zombie(std::string n) :
	name{ n }
{}

Zombie::~Zombie()
{
	std::cout << "Destructor: " << name << '\n';
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << '\n';
}
