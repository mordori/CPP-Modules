#include "ClapTrap.hpp"

#include <string>
#include <iostream>
#include <iomanip>

#include "io.hpp"

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
	if (!m_hitPoints || !m_energyPoints)
		std::cout << std::setw(40) << m_name + " tries to ATTACK: ";
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
	std::cout << std::setw(40) << m_name + " ATTACKs " + target + ": ";
	std::cout << "caused " << m_attackDamage << " DMG!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	IosFlags flags{ std::cout };
	std::cout << std::left;
	std::cout << std::setw(40) << m_name + " is DAMAGED: ";
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
	std::cout << std::setw(40) << m_name + " tries to REPAIR itself:";
	if (!m_energyPoints)
	{
		std::cout << "out of energy!\n";
		return;
	}
	--m_energyPoints;
	++m_hitPoints;
	std::cout << "healed " << amount << " HP!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return *this;
	std::cout << "\033[1;34mClapTrap::Assignment (" << m_name << " <- " << other.m_name << ")\033[0m\n";
	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;
	return *this;
}
