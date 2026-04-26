#pragma once

#include <string>

class Weapon;

class HumanA
{
private:
	std::string m_name{};
	const Weapon& m_weapon;

public:
	HumanA(const std::string& name, const Weapon& weapon);

	void attack() const;
};
