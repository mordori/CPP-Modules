#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	const std::string dummy{ "Dummy" };

	{
		ClapTrap clap{ "Clap" };
		ScavTrap scav{ "Scav" };
		FragTrap frag{ "Frag" };

		frag.attack(dummy);
		frag.highFivesGuys();
	}
	return 0;
}
