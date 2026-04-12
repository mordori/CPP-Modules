#include "phonebook.h"
#include "input.h"

#include <cstddef>
#include <iostream>
#include <iomanip>

void PhoneBook::addContact()
{
	std::cout << "--- Adding New Contact ---" << "\n\n";

	Contact newContact{};
	newContact.initialize();

	m_contacts[m_index++] = newContact;
	m_index &= MAX_CONTACTS - 1;
	if (m_addedContacts < MAX_CONTACTS)
		++m_addedContacts;

	clearTerminal();
	std::cout << '\n'
		<< newContact.getFirstName() << " " << newContact.getLastName()
		<< " added to contacts!" << "\n\n";
}

void PhoneBook::searchContact()
{
	showContacts();
	std::cout << '\n';
	long index{extractInput("Enter index: ")};
	if (m_addedContacts == 0)
		std::cout << "You have not added any contacts." << "\n\n";
	else if (index < 1)
		std::cout << "Indexes are positive and start from 1." << "\n\n";
	else if (static_cast<std::size_t>(index) > m_addedContacts)
		std::cout << "You only have " << m_addedContacts << " contacts added." << "\n\n";
	else
		displayContactDetails(static_cast<std::size_t>(index));
}

void PhoneBook::showContacts()
{
	std::cout << "--- Contact List ---" << "\n\n";
	std::ios_base::fmtflags original = std::cout.flags();
	std::cout << std::right;
	for (size_t i{}; i < m_addedContacts; i++)
		showContact(m_contacts[i], i);
	std::cout.flags(original);
}

void PhoneBook::showContact(const Contact& contact, std::size_t index)
{
	int width{10};
	std::cout << std::setw(width) << index + 1 << '|';
	displayField(contact.getFirstName(), '|');
	displayField(contact.getLastName(), '|');
	displayField(contact.getNickname(), '\n');
}

void PhoneBook::displayField(std::string_view field, char delimiter)
{
	int width{10};
	if (field.length() <= static_cast<std::size_t>(width))
		std::cout << std::setw(width) << field << delimiter;
	else
		std::cout << std::string_view(field.data(), 9) << '.' << delimiter;
}

void PhoneBook::displayContactDetails(std::size_t index)
{
	std::cout << '\n' << "--- Contact Details ---" << "\n\n";
	std::cout << m_contacts[index - 1] << '\n';
}
