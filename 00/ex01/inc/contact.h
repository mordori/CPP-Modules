#pragma once

#include <string>
#include <iosfwd>

class Contact
{
private:
	std::string m_firstName{};
	std::string m_lastName{};
	std::string m_nickname{};
	std::string m_phoneNumber{};
	std::string m_darkestSecret{};

public:
	Contact();
	Contact(std::string firstName,
			std::string lastName,
			std::string nickname,
			std::string phoneNumber,
			std::string darkestSecret);
	~Contact();
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);

	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNickname(const std::string& nickname);
	void setPhoneNumber(const std::string& phoneNumber);
	void setDarkestSecret(const std::string& darkestSecret);
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickname() const;
	const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;
};

std::ostream& operator<<(std::ostream& os, const Contact& contact);
