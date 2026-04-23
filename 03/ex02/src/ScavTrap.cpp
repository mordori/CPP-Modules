#include "ScavTrap.hpp"

#include <string>
#include <iostream>
#include <iomanip>

#include "io.hpp"

ScavTrap::ScavTrap(const std::string &name) :
	ClapTrap{ name, 100, 50, 20 }
{ std::cout << "\033[1;34mScavTrap::Constructor (" << m_name << ")\033[0m\n"; }

ScavTrap::ScavTrap(const ScavTrap& other) :
	ClapTrap{ other }
{ std::cout << "\033[1;34mScavTrap::Copy Constructor (" << m_name << ")\033[0m\n"; }

ScavTrap::~ScavTrap()
{ std::cout << "\033[1;34mScavTrap::Destructor (" << m_name << ")\033[0m\n"; }

void ScavTrap::attack(const std::string& target)
{
	IosFlags flags{ std::cout };
	std::cout << std::left;
	std::cout << std::setw(COL_WIDTH) << m_name + " (ScavTrap)" + " tries to ATTACK " + target + ": ";
	if (!m_hitPoints)
	{
		std::cout << "out of HP!\n";
		return;
	}
	if (!m_energyPoints)
	{
		std::cout << "out of energy!\n";
		return;
	}
	--m_energyPoints;
	std::cout << "caused " << m_attackDamage << " DMG!\n";
}

void ScavTrap::guardGate()
{
	std::cout << m_name + " GUARDs the gate!\n";
}
