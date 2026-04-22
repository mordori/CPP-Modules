#include <string>

#include "ClapTrap.hpp"

int main()
{
	const std::string dummy{ "Dummy"};

	ClapTrap clap{ "Clap" };
	clap.attack(dummy);
	clap.takeDamage(3);
	clap.takeDamage(20);
	clap.takeDamage(10);
	clap.attack(dummy);
	clap.beRepaired(__UINT32_MAX__);
	clap.takeDamage(1);
	clap.beRepaired(12);
	clap.takeDamage(10);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.attack(dummy);
	clap.beRepaired(1);
	ClapTrap clap2{ clap };
	clap2.attack(dummy);
	ClapTrap clap3{ "Clap3" };
	clap2 = clap3;
	clap2.attack(dummy);
	return 0;
}
