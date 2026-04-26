#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <cstddef>
#include <utility>
#include <stdexcept>

#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, std::size_t grade) :
	m_name{ std::move(name) },
	m_grade{ grade }
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException{ "Bureaucrat::Construction aborted: " + m_name };
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException{ "Bureaucrat::Construction aborted: " + m_name };
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) :
	std::out_of_range{ msg + ": Grade is too high!" }
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) :
	std::out_of_range{ msg + ": Grade is too low!" }
{}

void Bureaucrat::incrementGrade()
{
	if (m_grade <= 1)
		throw Bureaucrat::GradeTooHighException{ "Grade increment aborted: " + m_name };
	--m_grade;
}

void Bureaucrat::decrementGrade()
{
	if (m_grade >= 150)
		throw Bureaucrat::GradeTooLowException{ "Grade decrement aborted: " + m_name };
	++m_grade;
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << ".\n";
	}
	catch(const std::exception& e)
	{
		std::cout << m_name << " couldn't sign " << form.getName() << ", because their " << e.what() << ".\n";
	}
}

const std::string& Bureaucrat::getName() const
{ return m_name; }

std::size_t Bureaucrat::getGrade() const
{ return m_grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() + ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}
