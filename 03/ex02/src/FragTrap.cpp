#include "FragTrap.hpp"

#include <string>
#include <iostream>

FragTrap::FragTrap(const std::string &name) :
	ClapTrap{ name, 100, 100, 30 }
{ std::cout << "\033[1;34mFragTrap::Constructor (" << m_name << ")\033[0m\n"; }

FragTrap::FragTrap(const FragTrap& other) :
	ClapTrap{ other }
{ std::cout << "\033[1;34mFragTrap::Copy Constructor (" << m_name << ")\033[0m\n"; }

FragTrap::~FragTrap()
{ std::cout << "\033[1;34mFragTrap::Destructor (" << m_name << ")\033[0m\n"; }

void FragTrap::highFivesGuys()
{
	std::cout << m_name + " gives the guys a HIGH FIVE!\n";
}
