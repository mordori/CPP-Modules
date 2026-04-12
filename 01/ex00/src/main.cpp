#include "Zombie.hpp"

int main()
{
	Zombie* john = newZombie("John");
	john->announce();
	randomChump("Jane");
	delete john;
	return 0;
}
