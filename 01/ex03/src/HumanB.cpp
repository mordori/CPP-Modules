#include "HumanB.hpp"

#include <string>
#include <iostream>

#include "Weapon.hpp"

HumanB::HumanB(const std::string& name) :
	m_name{ name }
{}

void HumanB::attack() const
{
	std::cout << m_name << " attacks with their " << (m_weapon ? m_weapon->getType() : "bare hands") << '\n';
}

void HumanB::setWeapon(const Weapon& weapon)
{ m_weapon = &weapon; }
