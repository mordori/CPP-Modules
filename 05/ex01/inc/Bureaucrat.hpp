#pragma once

#include <stdexcept>
#include <string>
#include <cstddef>
#include <iosfwd>

class Form;

class Bureaucrat
{
private:
	const std::string m_name{};
	std::size_t m_grade{};

public:
	struct GradeTooHighException : public std::out_of_range
	{ GradeTooHighException(const std::string& msg); };

	struct GradeTooLowException : public std::out_of_range
	{ GradeTooLowException(const std::string& msg); };

	Bureaucrat() = delete;
	Bureaucrat(std::string name, std::size_t grade);
	Bureaucrat(const Bureaucrat& other) = default;
	~Bureaucrat() = default;

	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form) const;

	const std::string& getName() const;
	std::size_t getGrade() const;

	Bureaucrat& operator=(const Bureaucrat& other) = delete;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
