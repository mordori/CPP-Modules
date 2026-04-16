#include "HumanA.hpp"

#include <string>
#include <iostream>

#include "Weapon.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon) :
	m_name{ name }, m_weapon{ weapon }
{}

void HumanA::attack() const
{
	std::cout << m_name << " attacks with their " << m_weapon.getType() << '\n';
}
