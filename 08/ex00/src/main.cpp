#include <optional>
#include <array>
#include <vector>
#include <map>
#include <iostream>

#include "easyfind.hpp"

int main()
{
	std::array<int, 3> a{ 1, 2, 3 };

	int i{ 2 };
	std::cout << (easyfind(a, 2) ? "FOUND" : "NOT FOUND") ;
	return 0;
}
