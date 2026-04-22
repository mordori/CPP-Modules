#include "ClapTrap.hpp"

#include <string>
#include <iostream>
#include <iomanip>

#include "io.hpp"

ClapTrap::ClapTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int dmg) :
	m_name{ name },
	m_hitPoints{ hp },
	m_energyPoints{ ep },
	m_attackDamage{ dmg }
{ std::cout << "\033[1;34mClapTrap::Constructor (" << m_name << ") [protected]\033[0m\n"; }

ClapTrap::ClapTrap(const std::string& name) :
	m_name{ name }
{ std::cout << "\033[1;34mClapTrap::Constructor (" << m_name << ")\033[0m\n"; }

ClapTrap::ClapTrap(const ClapTrap& other) :
	m_name{ other.m_name },
	m_hitPoints{ other.m_hitPoints },
	m_energyPoints{ other.m_energyPoints },
	m_attackDamage{ other.m_attackDamage }
{ std::cout << "\033[1;34mClapTrap::Copy Constructor (" << m_name << ")\033[0m\n"; }

ClapTrap::~ClapTrap()
{ std::cout << "\033[1;34mClapTrap::Destructor (" << m_name << ")\033[0m\n"; }

void ClapTrap::attack(const std::string& target)
{
	IosFlags flags{ std::cout };
	std::cout << std::left;
	std::cout << std::setw(COL_WIDTH) << m_name + " (ClapTrap)" + " tries to ATTACK " + target + ": ";
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

void ClapTrap::takeDamage(unsigned int amount)
{
	IosFlags flags{ std::cout };
	std::cout << std::left;
	std::cout << std::setw(COL_WIDTH) << m_name + " is DAMAGED: ";
	if (!m_hitPoints)
	{
		std::cout << "lost 0 HP (out of HP)!\n";
		return;
	}
	if (m_hitPoints < amount)
	{
		std::cout << "lost " << m_hitPoints << " HP (-" << amount - m_hitPoints << " HP overkill)!\n";
		m_hitPoints = 0;
	}
	else
	{
		m_hitPoints -= amount;
		std::cout << "lost " << amount << " HP!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	IosFlags flags{ std::cout };
	std::cout << std::left;
	std::cout << std::setw(COL_WIDTH) << m_name + " tries to REPAIR itself:";
	if (!m_energyPoints)
	{
		std::cout << "out of energy!\n";
		return;
	}
	--m_energyPoints;
	if (m_hitPoints > __UINT32_MAX__ - amount)
	{
		std::cout << "healed " << __UINT32_MAX__ - m_hitPoints << " HP!\n";
		m_hitPoints = __UINT32_MAX__;
	}
	else
	{
		m_hitPoints += amount;
		std::cout << "healed " << amount << " HP!\n";
	}
}
