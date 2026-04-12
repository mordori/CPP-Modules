#include "Zombie.hpp"

#include <iostream>

Zombie::~Zombie()
{
	std::cout << "Destructor: " << name << '\n';
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << '\n';
}

void Zombie::setName(const std::string& n)
{ name = n; }
