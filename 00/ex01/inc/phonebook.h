#pragma once

#include "contact.h"

class PhoneBook
{
private:
	Contact	m_contacts[8]{};
public:
	void	addContact();
	void	searchContact();
};
