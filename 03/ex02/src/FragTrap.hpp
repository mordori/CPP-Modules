#pragma once

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
public:
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	~FragTrap() override;

	void highFivesGuys();

	FragTrap& operator=(const FragTrap& other) = default;
};
