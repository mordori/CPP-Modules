#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:

public:
	ShrubberyCreationForm() = delete;
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other) = default;
	~ShrubberyCreationForm() = default;

	void beSigned(const Bureaucrat& bureaucrat) override;
	void execute(const Bureaucrat& executor) const override;

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
};
