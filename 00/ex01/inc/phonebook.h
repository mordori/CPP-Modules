#pragma once

#include "contact.h"

#include <cstddef>
#include <string_view>

class PhoneBook
{
private:
	static constexpr std::size_t MAX_CONTACTS{ 8 };
	static constexpr std::size_t COL_WIDTH{ 10 };

	Contact m_contacts[MAX_CONTACTS]{};
	std::size_t m_index{};
	std::size_t m_addedContacts{};

	void showContacts();
	void showContact(const Contact& contact, std::size_t index);
	void displayField(std::string_view field, char delimiter);
	void displayContactDetails(std::size_t index);

public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& other);
	PhoneBook& operator=(const PhoneBook& other);

	void addContact();
	void searchContact();
};
