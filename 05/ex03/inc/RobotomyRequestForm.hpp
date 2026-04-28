#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:
	RobotomyRequestForm() = delete;
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other) = default;
	~RobotomyRequestForm() override = default;

	void execute(const Bureaucrat& executor) const override;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
};
