#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm() = delete;

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other) = default;
	~ShrubberyCreationForm() override = default;

	void execute(const Bureaucrat& executor) const override;
};
