#include "Zombie.hpp"

int main()
{
	constexpr int size{ 10 };
	Zombie* horde = zombieHorde(size, "John");
	for (int i{}; i < size; ++i)
		horde[i].announce();
	delete[] horde;
	return 0;
}
