#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm() = delete;

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other) = default;
	~PresidentialPardonForm() override = default;

	void execute(const Bureaucrat& executor) const override;
};
