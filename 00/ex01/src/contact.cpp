#include "contact.h"
#include "io.h"

#include <iostream>
#include <iomanip>

Contact::Contact()
{}

Contact::Contact(std::string firstName,
				std::string lastName,
				std::string nickname,
				std::string phoneNumber,
				std::string darkestSecret) :
	m_firstName{ std::move(firstName) },
	m_lastName{ std::move(lastName) },
	m_nickname{ std::move(nickname) },
	m_phoneNumber{ std::move(phoneNumber) },
	m_darkestSecret{ std::move(darkestSecret) }
{}

Contact::~Contact()
{}

Contact::Contact(const Contact& other) :
	m_firstName{ other.m_firstName },
	m_lastName{ other.m_lastName },
	m_nickname{ other.m_nickname },
	m_phoneNumber{ other.m_phoneNumber },
	m_darkestSecret{ other.m_darkestSecret }
{}

Contact& Contact::operator=(const Contact& other)
{
	if (this == &other)
		return *this;
	m_firstName = other.m_firstName;
	m_lastName = other.m_lastName;
	m_nickname = other.m_nickname;
	m_phoneNumber = other.m_phoneNumber;
	m_darkestSecret = other.m_darkestSecret;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
	IosFlags flags{ os };
	int w{ 18 };
	os << std::left;
	os
		<< std::setw(w) << "First Name: " << contact.getFirstName() << '\n'
		<< std::setw(w) << "Last Name: " << contact.getLastName() << '\n'
		<< std::setw(w) << "Nickname: " << contact.getNickname() << '\n'
		<< std::setw(w) << "Phone Number: " << contact.getPhoneNumber() << '\n'
		<< std::setw(w) << "Darkest Secret: " << contact.getDarkestSecret() << '\n';
	return os;
}

#pragma region Setters

void Contact::setFirstName(const std::string& firstName)
{ m_firstName = firstName; }

void Contact::setLastName(const std::string& lastName)
{ m_lastName = lastName; }

void Contact::setNickname(const std::string& nickname)
{ m_nickname = nickname; }

void Contact::setPhoneNumber(const std::string& phoneNumber)
{ m_phoneNumber = phoneNumber; }

void Contact::setDarkestSecret(const std::string& darkestSecret)
{ m_darkestSecret = darkestSecret; }

#pragma endregion

#pragma region Getters

const std::string& Contact::getFirstName() const
{ return m_firstName; }

const std::string& Contact::getLastName() const
{ return m_lastName; }

const std::string& Contact::getNickname() const
{ return m_nickname; }

const std::string& Contact::getPhoneNumber() const
{ return m_phoneNumber; }

const std::string& Contact::getDarkestSecret() const
{ return m_darkestSecret; }

#pragma endregion
