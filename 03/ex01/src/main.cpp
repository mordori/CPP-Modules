#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	const std::string dummy{ "Dummy"};

	{
		ScavTrap scav{ "Scav" };
		scav.attack(dummy);
		scav.takeDamage(3);
		scav.takeDamage(20);
		scav.takeDamage(10);
		scav.attack(dummy);
		scav.beRepaired(1);
		ScavTrap scav2{ "Scav2" };
		scav2.guardGate();
	}

	std::cout << '\n';

	{
		ScavTrap scav{ "Scav" };
		ScavTrap scav2{ "Scav2" };
		scav.takeDamage(1000);
		scav2 = scav;
		scav2.attack(dummy);

		ScavTrap scav3{ scav2 };
		scav3.attack(dummy);
	}

	std::cout << '\n';

	{
		ScavTrap scav{ "Scav" };
		ClapTrap clap{ scav };		// Object slicing
		scav.takeDamage(1000);
		scav.attack(dummy);
		clap.attack(dummy);
	}

	std::cout << '\n';

	// Dynamic/Static binding with virtual/method hiding
	// with vtable override *this is silently promoted with a cast
	{
		ClapTrap* scavClap = new ScavTrap{ "ScavClap" };
		scavClap->attack(dummy);

		ScavTrap scavvy{ "Scavvy" };
		ClapTrap& clappy = scavvy;
		clappy.attack(dummy);

		delete scavClap;
	}

	return 0;
}
