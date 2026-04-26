#include "Form.hpp"

#include <iostream>
#include <string>
#include <cstddef>
#include <utility>
#include <stdexcept>

#include "Bureaucrat.hpp"

Form::Form(std::string name, std::size_t signGrade, std::size_t execGrade) :
	m_name{ std::move(name) },
	m_signGrade{ signGrade },
	m_execGrade{ execGrade }
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException{ "Construction aborted: " + m_name + ": Grade is too high!" };
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException{ "Construction aborted: " + m_name + ": Grade is too low!" };
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) :
	std::out_of_range{ msg }
{}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) :
	std::out_of_range{ msg }
{}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_signGrade)
		throw Form::GradeTooLowException{ "grade is too low" };
	m_isSigned = true;
}

const std::string& Form::getName() const { return m_name; }

bool Form::getIsSigned() const
{ return m_isSigned; }

std::size_t Form::getSignGrade() const
{ return m_signGrade; }

std::size_t Form::getExecGrade() const
{ return m_execGrade; }

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", form "
		<< (form.getIsSigned() ? "(SIGNED)" : "(UNSIGNED)")
		<< ". Grade to sign: " << form.getSignGrade()
		<< ". Grade to execute: " << form.getExecGrade() << ".\n";
	return os;
}
