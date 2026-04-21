#include "ClapTrap.hpp"

#include <string>
#include <iostream>
#include <format>

ClapTrap::ClapTrap(const std::string& name) :
	m_name{ name }
{ std::cout << std::format("\033[1;34mClapTrap::Constructor ({})\033[0m\n", m_name); }

ClapTrap::ClapTrap(const ClapTrap& other) :
	m_name{ other.m_name },
	m_hitPoints{ other.m_hitPoints },
	m_energyPoints{ other.m_energyPoints },
	m_attackDamage{ other.m_attackDamage }
{ std::cout << std::format("\033[1;34mClapTrap::Copy Constructor ({})\033[0m\n", m_name); }

ClapTrap::~ClapTrap()
{ std::cout << std::format("\033[1;34mClapTrap::Destructor ({})\033[0m\n", m_name); }

void ClapTrap::attack(const std::string& target)
{
	if (!m_hitPoints || !m_energyPoints)
		std::cout << std::format("{:40}", m_name + " tries to ATTACK: ");
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
	std::cout << std::format("{:40}caused {} DMG!\n", m_name + " ATTACKs " + target + ": ", m_attackDamage);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::format("{:40}", m_name + " is DAMAGED: ");
	if (!m_hitPoints)
	{
		std::cout << "lost 0 HP (out of HP)!\n";
		return;
	}
	if (m_hitPoints < amount)
	{
		std::cout << std::format("lost {} HP (-{} HP overkill)!\n", m_hitPoints, amount - m_hitPoints);
		m_hitPoints = 0;
	}
	else
	{
		m_hitPoints -= amount;
		std::cout << std::format("lost {} HP!\n", amount);
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!m_energyPoints)
	{
		std::cout << std::format("{:40}out of energy!\n", m_name + " tries to REPAIR itself:");
		return;
	}
	--m_energyPoints;
	++m_hitPoints;
	std::cout << std::format("{:40}healed {} HP!\n", m_name + " REPAIRs itself: ", amount);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return *this;
	std::cout << std::format("\033[1;34mClapTrap::Assignment ({} <- {})\033[0m\n", m_name, other.m_name);
	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;
	return *this;
}
