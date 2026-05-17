#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::~Zombie() {
	std::cout << "Destructor: " << name << '\n';
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << '\n';
}

void Zombie::setName(const std::string& n) {
	name = n;
}
