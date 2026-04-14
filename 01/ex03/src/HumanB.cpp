#include "HumanB.hpp"
#include "Weapon.hpp"

#include <string>
#include <iostream>

HumanB::HumanB(const std::string& name) :
	m_name{ name }
{}

void HumanB::attack() const
{
	if (m_weapon)
		std::cout << m_name << " attacks with their " << m_weapon->getType() << '\n';
	else
		std::cout << m_name << " attacks with their bare hands" << '\n';
}

void HumanB::setWeapon(const Weapon& weapon)
{ m_weapon = &weapon; }
