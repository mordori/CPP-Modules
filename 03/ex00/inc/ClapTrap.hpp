#pragma once

#include <string>

class ClapTrap
{
private:
	std::string m_name{};
	unsigned int m_hitPoints{10};
	unsigned int m_energyPoints{10};
	unsigned int m_attackDamage{0};

public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap& operator=(const ClapTrap& other);
};
