#pragma once

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	RobotomyRequestForm() = delete;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other) = default;
	~RobotomyRequestForm() override = default;

	void execute(const Bureaucrat& executor) const override;
};
