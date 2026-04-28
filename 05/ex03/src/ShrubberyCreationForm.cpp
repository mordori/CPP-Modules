#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <utility>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm{ "Shrubbery Creation Form", std::move(target), 145, 137 }
{}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::string fileName{ getTarget() + "_shrubbery" };
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
