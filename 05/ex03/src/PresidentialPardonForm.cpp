#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <utility>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm{ "Presidential Pardon Form", std::move(target), 25, 5 }
{}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
