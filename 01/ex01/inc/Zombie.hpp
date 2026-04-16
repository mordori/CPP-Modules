#pragma once

#include <string>

class Zombie
{
private:
	std::string name{};

public:
	Zombie() = default;
	~Zombie();

	void announce();
	void setName(const std::string& n);
};

Zombie* zombieHorde(int N, std::string name);
