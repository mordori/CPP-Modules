#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <random>
#include <utility>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm{ "Robotomy Request Form", std::move(target), 72, 45 }
{}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "*DRILLING NOISES*\n";
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution random01{ 0, 1 };
	if (random01(mt))
		std::cout << getTarget() << " succesfully robotomized.\n";
	else
		std::cout << "Robotomy failed.\n";
}
