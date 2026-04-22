#include <string>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	const std::string dummy{ "Dummy"};

	// ScavTrap scav{ "Scav" };
	// scav.attack(dummy);
	// scav.takeDamage(3);
	// scav.takeDamage(20);
	// scav.takeDamage(10);
	// scav.attack(dummy);
	// scav.beRepaired(1);

	// ScavTrap scav2{ "Scav2" };
	// scav.takeDamage(1000);
	// scav2 = scav;
	// scav2.attack(dummy);

	// ScavTrap scav3{ scav2 };
	// scav3.attack(dummy);

	ScavTrap scav4{ "Scav4" };
	ClapTrap clap{ scav4 };		// Object slicing
	scav4.takeDamage(1000);
	scav4.attack(dummy);
	clap.attack(dummy);

	ClapTrap* scavClap = new ScavTrap{ "ScavClap" };	// Static binding, no true overriding
	scavClap->attack(dummy);
	delete scavClap;

	ScavTrap scavvy{ "Scavvy" };
	ClapTrap& clappy = scavvy;
	clappy.attack(dummy);

	return 0;
}
