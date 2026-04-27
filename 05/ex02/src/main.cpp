#include <iostream>
#include <exception>
#include <cstddef>
#include <utility>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		RobotomyRequestForm s{ "S" };
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	return 0;
}
