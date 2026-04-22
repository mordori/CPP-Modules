#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap() override;

	void guardGate();

	void attack(const std::string& target) override;

	ScavTrap& operator=(const ScavTrap& other) = default;
};
