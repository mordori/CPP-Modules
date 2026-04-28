#include <iostream>
#include <exception>
#include <cstddef>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form a01{ "A01", 0, 1 };
		std::cout << a01;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	try
	{
		Form a10{ "A10", 1, 0 };
		std::cout << a10;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	try
	{
		Form a1510{ "A1510", 151, 0 };
		std::cout << a1510;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	try
	{
		Form a0151{ "A1510", 0, 151 };
		std::cout << a0151;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try
	{
		Bureaucrat bill{ "Bill", 2 };
		std::cout << bill;
		Form a1{ "A1", 1, 1 };
		std::cout << a1;
		bill.signForm(a1);
		bill.incrementGrade();
		std::cout << bill;
		bill.signForm(a1);
		std::cout << a1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	return 0;
}
