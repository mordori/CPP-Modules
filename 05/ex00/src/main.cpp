#include <iostream>
#include <exception>
#include <cstddef>

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bill{ "Bill", 0 };
		std::cout << bill;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat barbara{ "Barbara", 155 };
		std::cout << barbara;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat jane{ "Jane", 2 };
		std::cout << jane;
		while (true)
		{
			jane.incrementGrade();
			std::cout << jane;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat joe{ "Joe", 148 };
		std::cout << joe;
		while (true)
		{
			joe.decrementGrade();
			std::cout << joe;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	return 0;
}
