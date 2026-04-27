#pragma once

#include <stdexcept>
#include <string>
#include <cstddef>
#include <iosfwd>

class Bureaucrat;

class AForm
{
private:
	const std::string m_name{};
	bool m_isSigned{};
	const std::size_t m_signGrade{};
	const std::size_t m_execGrade{};

protected:
	struct GradeTooHighException : public std::out_of_range
	{
		GradeTooHighException(const std::string& msg);
	};

	struct GradeTooLowException : public std::out_of_range
	{
		GradeTooLowException(const std::string& msg);
	};

	AForm() = delete;
	AForm(std::string name, std::size_t signGrade, std::size_t execGrade);
	AForm(const AForm& other) = default;
	~AForm() = default;

	AForm& operator=(const AForm& other) = delete;

public:
	virtual void beSigned(const Bureaucrat& bureaucrat) = 0;
	virtual void execute(const Bureaucrat& executor) const = 0;

	const std::string& getName() const;
	bool getIsSigned() const;
	std::size_t getSignGrade() const;
	std::size_t getExecGrade() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
