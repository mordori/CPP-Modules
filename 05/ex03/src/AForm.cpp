#include "AForm.hpp"

#include <iostream>
#include <string>
#include <cstddef>
#include <utility>
#include <stdexcept>

#include "Bureaucrat.hpp"

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) :
	std::out_of_range{ msg }
{}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) :
	std::out_of_range{ msg }
{}

AForm::AForm(std::string name, std::string target, std::size_t signGrade, std::size_t execGrade) :
	m_name{ std::move(name) },
	m_target{ std::move(target) },
	m_signGrade{ signGrade },
	m_execGrade{ execGrade }
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException{ "Form::Construction aborted: " + m_name + ": Grade is too high!" };
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException{ "Form::Construction aborted: " + m_name + ": Grade is too low!" };
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_signGrade)
		throw AForm::GradeTooLowException{ "their grade is too low" };
	m_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!m_isSigned)
	{
		throw std::logic_error{ "the form has not been signed" };
	}
	if (executor.getGrade() > m_execGrade)
	{
		throw AForm::GradeTooLowException{ "their grade is too low" };
	}
}

const std::string& AForm::getName() const
{ return m_name; }

const std::string& AForm::getTarget() const
{ return m_target; }

bool AForm::getIsSigned() const
{ return m_isSigned; }

std::size_t AForm::getSignGrade() const
{ return m_signGrade; }

std::size_t AForm::getExecGrade() const
{ return m_execGrade; }

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", form "
		<< (form.getIsSigned() ? "(SIGNED)" : "(UNSIGNED)")
		<< ". Grade to sign: " << form.getSignGrade()
		<< ". Grade to execute: " << form.getExecGrade() << ".\n";
	return os;
}
