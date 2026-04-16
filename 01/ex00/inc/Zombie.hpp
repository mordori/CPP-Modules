#pragma once

#include <string>

class Zombie
{
private:
	std::string name{};

public:
	Zombie(std::string n);
	~Zombie();

	void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
