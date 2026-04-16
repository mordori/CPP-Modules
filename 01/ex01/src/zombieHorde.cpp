#include "Zombie.hpp"

#include <string>

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;
	Zombie* horde = new Zombie[N];
	for (int i{}; i < N; ++i)
		horde[i].setName(name);
	return horde;
}
