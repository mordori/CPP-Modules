#include <string>

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap{ "Clap" };
	const std::string dummy{ "Target Dummy"} ;
	clap.attack(dummy);
	clap.takeDamage(3);
	clap.takeDamage(20);
	clap.takeDamage(10);
	clap.attack(dummy);
	clap.beRepaired(1);
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
	ClapTrap clap3{ "Clap-3" };
	clap2 = clap3;
	clap2.attack(dummy);
	return 0;
}
