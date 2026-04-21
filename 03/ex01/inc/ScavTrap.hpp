#pragma once

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : ClapTrap
{
private:

public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ScavTrap& operator=(const ScavTrap& other);
};
