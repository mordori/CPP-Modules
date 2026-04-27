#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm{ "Presidential Pardon", 25, 5 }
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

void PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
	(void)bureaucrat;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	executor.executeForm(*this);
}
