#pragma once

#include <string>

class AForm;

class Intern
{
private:

public:
	Intern() = default;
	Intern(const Intern& other) = default;
	~Intern() = default;

	AForm* makeForm(const std::string& str, std::string target) const;

	Intern& operator=(const Intern& other) = default;
};
