#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bill{ "Bill", 45 };
		std::cout << bill;
		RobotomyRequestForm form{ "Jane" };
		bill.signForm(form);
		std::cout << form;
		bill.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat joe{ "Joe", 65 };
		std::cout << joe;
		ShrubberyCreationForm form{ "Garden" };
		joe.signForm(form);
		std::cout << form;
		joe.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat barbara{ "Barbara", 50 };
		std::cout << barbara;
		PresidentialPardonForm form{ "Jess" };
		barbara.signForm(form);
		std::cout << form;
		barbara.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	return 0;
}
