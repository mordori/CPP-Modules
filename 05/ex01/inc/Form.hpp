#pragma once

#include <stdexcept>
#include <string>
#include <cstddef>
#include <iosfwd>

class Bureaucrat;

class Form
{
private:
	const std::string m_name{};
	bool m_isSigned{};
	const std::size_t m_signGrade{};
	const std::size_t m_execGrade{};

public:
	struct GradeTooHighException : public std::out_of_range
	{
		GradeTooHighException(const std::string& msg);
	};

	struct GradeTooLowException : public std::out_of_range
	{
		GradeTooLowException(const std::string& msg);
	};

	Form() = delete;
	Form(std::string name, std::size_t signGrade, std::size_t execGrade);
	Form(const Form& other) = default;
	~Form() = default;

	void beSigned(const Bureaucrat& bureaucrat);

	const std::string& getName() const;
	bool getIsSigned() const;
	std::size_t getSignGrade() const;
	std::size_t getExecGrade() const;

	Form& operator=(const Form& other) = delete;
};

std::ostream& operator<<(std::ostream& os, const Form& form);
