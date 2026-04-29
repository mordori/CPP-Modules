#include "Intern.hpp"

#include <string>
#include <iostream>
#include <cstddef>
#include <utility>
#include <stdexcept>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum class FormType
{
	PRESIDENTIAL_PARDON,
	ROBOTOMY_REQUEST,
	SHRUBBERY_CREATION,
	UNDEFINED
};

static FormType parseForm(const std::string& str)
{
	static const std::string forms[]{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	for (size_t i{}; i < 3; ++i)
	{
		if (forms[i] == str)
			return static_cast<FormType>(i);
	}
	return FormType::UNDEFINED;
}

AForm* Intern::makeForm(const std::string& str, std::string target) const
{
	AForm* form{};
	switch (parseForm(str))
	{
	case FormType::PRESIDENTIAL_PARDON:
		form = new PresidentialPardonForm{ std::move(target) }; break;
	case FormType::ROBOTOMY_REQUEST:
		form = new RobotomyRequestForm{ std::move(target) }; break;
	case FormType::SHRUBBERY_CREATION:
		form = new ShrubberyCreationForm{ std::move(target) }; break;
	case FormType::UNDEFINED:
	default:
		throw std::logic_error{ "Intern can't create such form!" };
	}
	std::cout << "Intern creates " << form->getName() << ".\n";
	return form;
}
