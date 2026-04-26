#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <cstddef>
#include <utility>
#include <stdexcept>

Bureaucrat::Bureaucrat(std::string name, std::size_t grade) :
	m_name{ std::move(name) }
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException{ m_name + ": Construction aborted: Grade is too high!" };
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException{ m_name + ": Construction aborted: Grade is too low!" };
	m_grade = grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) :
	std::out_of_range{ msg }
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) :
	std::out_of_range{ msg }
{}

void Bureaucrat::incrementGrade()
{
	if (m_grade <= 1)
		throw Bureaucrat::GradeTooHighException{ m_name + ": Grade increment aborted: Maximum!" };
	--m_grade;
}

void Bureaucrat::decrementGrade()
{
	if (m_grade >= 150)
		throw Bureaucrat::GradeTooLowException{ m_name + ": Grade decrement aborted: Minimum!" };
	++m_grade;
}

const std::string &Bureaucrat::getName() const
{ return m_name; }

std::size_t Bureaucrat::getGrade() const
{ return m_grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() + ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}
