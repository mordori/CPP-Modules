#pragma once

#include <cstddef>
#include <iosfwd>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat {
private:
	const std::string m_name{};
	std::size_t m_grade{};

	Bureaucrat() = delete;

	Bureaucrat& operator=(const Bureaucrat& other) = delete;

public:
	struct GradeTooHighException : public std::out_of_range {
		GradeTooHighException(const std::string& msg);
	};

	struct GradeTooLowException : public std::out_of_range {
		GradeTooLowException(const std::string& msg);
	};

	Bureaucrat(std::string name, std::size_t grade);
	Bureaucrat(const Bureaucrat& other) = default;
	~Bureaucrat() = default;

	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& form) const;
	void executeForm(const AForm& form) const;

	const std::string& getName() const;
	std::size_t getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
