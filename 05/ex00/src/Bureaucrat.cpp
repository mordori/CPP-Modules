#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <cstddef>

Bureaucrat::Bureaucrat(const std::string& name, std::size_t grade) :
	m_name{ name }
{

}

void Bureaucrat::incrementGrade()
{
}

void Bureaucrat::decrementGrade()
{
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
