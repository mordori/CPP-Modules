#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm{ target + "_shrubbery", 145, 137 }
{
	std::string fileName{ target + "_shrubbery" };
	std::ofstream outFile{ fileName };
	if (outFile.is_open())
	{
	outFile <<
		"               ,@@@@@@@,\n" <<
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" <<
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" <<
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" <<
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" <<
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" <<
		"   `&%\\ ` /%&'    |.|        \\ '|8'\n" <<
		"       |o|        | |         | |\n" <<
		"       |.|        | |         | |\n" <<
		" _____/ ._\\______/  ,\\_______/.  \\_____\n";
	}
	else
		std::cerr << "Couldn't create file <" << fileName << ">\n";
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
	(void)bureaucrat;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	executor.executeForm(*this);
}
