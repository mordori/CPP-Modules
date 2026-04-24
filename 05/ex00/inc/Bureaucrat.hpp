#pragma once

#include <exception>
#include <string>
#include <cstddef>
#include <iosfwd>

class Bureaucrat : public std::exception
{
private:
	const std::string m_name{};
	std::size_t m_grade{ 150 };

public:
	Bureaucrat(const std::string& m_name, std::size_t grade);
	Bureaucrat(const Bureaucrat& other) = default;
	~Bureaucrat() = default;

	void incrementGrade();
	void decrementGrade();

	const std::string& getName() const;
	std::size_t getGrade() const;

	const char* what() const noexcept;

	Bureaucrat& operator=(const Bureaucrat& other) = default;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
