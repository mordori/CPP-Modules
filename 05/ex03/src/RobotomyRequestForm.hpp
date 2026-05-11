#pragma once

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm() = delete;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other) = default;
	~RobotomyRequestForm() override = default;

	void execute(const Bureaucrat& executor) const override;
};
