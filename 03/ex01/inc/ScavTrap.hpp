#include "ClapTrap.hpp"

#include <string>

class ScavTrap : ClapTrap
{
private:

public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	void guardGate();

	ScavTrap& operator=(const ScavTrap& other);
};
