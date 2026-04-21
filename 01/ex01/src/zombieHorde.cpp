#include "Zombie.hpp"

#include <cstddef>
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;
	Zombie* horde = new Zombie[static_cast<size_t>(N)];
	for (int i{}; i < N; ++i)
		horde[i].setName(name);
	return horde;
}
