#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm() = delete;
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other) = default;
	~PresidentialPardonForm() = default;

	void beSigned(const Bureaucrat& bureaucrat) override;
	void execute(const Bureaucrat& executor) const override;

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
};
