#include "Harl.hpp"

#include <cstddef>
#include <string>
#include <string_view>
#include <iostream>

void Harl::debug()
{ std::cout << "debug" << '\n'; }

void Harl::info()
{ std::cout << "info" << '\n'; }

void Harl::warning()
{ std::cout << "warning" << '\n'; }

void Harl::error()
{ std::cout << "error" << '\n'; }

void Harl::complain(std::string level)
{
	constexpr std::size_t size{4};
	constexpr std::string_view levels[size]{ "DEBUG", "INFO", "WARNING", "ERROR" };
	constexpr void (Harl::*f[size])(){ &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (std::size_t i{}; i < size; ++i)
	{
		if (levels[i] == level)
			(this->*f[i])();
	}
}
