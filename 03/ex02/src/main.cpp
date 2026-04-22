#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	const std::string dummy{ "Dummy"};

	{
		ClapTrap clap{ "Clap" };
		ScavTrap scav{ "Scav" };
		FragTrap frag{ "Frag" };

		frag.attack(dummy);
		frag.highFivesGuys();
	}
	return 0;
}
