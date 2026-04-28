#include <iostream>
#include <exception>
#include <cstddef>
#include <memory>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bill{ "Bill", 99 };
		std::cout << bill;
		std::unique_ptr<AForm> form{ Intern{}.makeForm("presidential pardon", "Donald") };
		std::cout << *form;
		bill.signForm(*form);
		bill.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat hermes{ "Hermes", 1 };
		std::cout << hermes;
		std::unique_ptr<AForm> form{ Intern{}.makeForm("robotomy request", "Bender") };
		std::cout << *form;
		hermes.signForm(*form);
		hermes.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat janet{ "Janet", 20 };
		std::cout << janet;
		std::unique_ptr<AForm> form{ Intern{}.makeForm("shrubbery creation", "Garden") };
		std::cout << *form;
		janet.signForm(*form);
		janet.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat pirkko{ "Pirkko", 150 };
		std::cout << pirkko;
		std::unique_ptr<AForm> form{ Intern{}.makeForm("kela yleistuki", "Pekka") };
		std::cout << *form;
		pirkko.signForm(*form);
		pirkko.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
