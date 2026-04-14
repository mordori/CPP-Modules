#pragma once

#include <string>

class Weapon
{
private:
	std::string type{};

public:
	Weapon() = default;
	Weapon(const std::string& t);

	void setType(const std::string& t);
	const std::string& getType() const;
};
