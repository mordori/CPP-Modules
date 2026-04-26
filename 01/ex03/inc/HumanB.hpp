#pragma once

#include <string>

class Weapon;

class HumanB
{
private:
	std::string m_name{};
	const Weapon* m_weapon{};

public:
	HumanB(const std::string& name);

	void attack() const;
	void setWeapon(const Weapon& weapon);
};
