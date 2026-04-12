#include "phonebook.hpp"
#include "io.hpp"

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <optional>
#include <string>

PhoneBook::PhoneBook(const PhoneBook& other) :
	m_index{ other.m_index },
	m_addedContacts{ other.m_addedContacts }
{
	for (std::size_t i{}; i < other.m_addedContacts; ++i)
		m_contacts[i] = other.m_contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	if (this == &other)
		return *this;
	m_index = other.m_index;
	m_addedContacts = other.m_addedContacts;
	for (std::size_t i{}; i < other.m_addedContacts; ++i)
		m_contacts[i] = other.m_contacts[i];
	return *this;
}

void PhoneBook::addContact()
{
	std::cout << "--- Adding New Contact ---" << "\n\n";
	std::string firstName{}, lastName{}, nickname{}, phoneNumber{}, darkestSecret{};
	extractInputTo(firstName, "First Name: ");
	extractInputTo(lastName, "Last Name: ");
	extractInputTo(nickname, "Nickname: ");
	extractInputTo(phoneNumber, "Phone Number: ");
	extractInputTo(darkestSecret, "Darkest Secret: ");

	Contact contact{ firstName, lastName, nickname, phoneNumber, darkestSecret };
	m_contacts[m_index] = contact;
	m_index = (m_index + 1) % MAX_CONTACTS;
	if (m_addedContacts < MAX_CONTACTS)
		++m_addedContacts;

	clearTerminal();
	std::cout << '\n'
		<< contact.getFirstName() << " " << contact.getLastName()
		<< " added to contacts!" << "\n\n";
}

void PhoneBook::searchContact()
{
	showContacts();
	std::cout << '\n';
	std::optional<std::size_t> input{ extractInput("Enter index: ") };
	if (!input.has_value())
		return;
	std::cout << '\n';
	std::size_t index = input.value();
	if (index < 1)
		std::cout << "Indexes start from 1." << "\n\n";
	else if (m_addedContacts == 0)
		std::cout << "You have not added any contacts." << "\n\n";
	else if (index > m_addedContacts)
		std::cout << "You only have " << m_addedContacts << " contact(s) added." << "\n\n";
	else
		displayContactDetails(static_cast<std::size_t>(index));
}

void PhoneBook::showContacts()
{
	std::cout << "--- Contact List ---" << "\n\n";
	IosFlags flags{ std::cout };
	std::cout << std::right;
	for (size_t i{}; i < m_addedContacts; ++i)
		showContact(m_contacts[i], i);
}

void PhoneBook::showContact(const Contact& contact, std::size_t index)
{
	std::cout << std::setw(static_cast<int>(COL_WIDTH)) << index + 1 << '|';
	displayField(contact.getFirstName(), '|');
	displayField(contact.getLastName(), '|');
	displayField(contact.getNickname(), '\n');
}

void PhoneBook::displayField(std::string_view field, char delimiter)
{
	if (field.length() <= COL_WIDTH)
		std::cout << std::setw(static_cast<int>(COL_WIDTH)) << field << delimiter;
	else
		std::cout << std::string_view(field.data(), 9) << '.' << delimiter;
}

void PhoneBook::displayContactDetails(std::size_t index)
{
	std::cout << "--- Contact Details ---" << "\n\n";
	std::cout << m_contacts[index - 1] << '\n';
}
