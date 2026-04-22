#pragma once

#include <string>

class ClapTrap
{
protected:
	static constexpr int COL_WIDTH{ 50 };

	std::string m_name{};
	unsigned int m_hitPoints{10};
	unsigned int m_energyPoints{10};
	unsigned int m_attackDamage{0};

	ClapTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int dmg);

public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	virtual ~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap& operator=(const ClapTrap& other) = default;
};
