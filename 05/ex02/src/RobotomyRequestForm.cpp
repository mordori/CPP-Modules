#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <random>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm{ "Robotomy Request", 72, 45 }
{
	std::cout << "*DRILLING NOISES*\n";
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution random01{ 0, 1 };
	if (random01(mt))
		std::cout << target << " succesfully robotomized.\n";
	else
		std::cout << "Robotomy failed.\n";
}

void RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
	(void)bureaucrat;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	executor.executeForm(*this);
}
