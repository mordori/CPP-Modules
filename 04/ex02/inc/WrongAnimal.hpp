#pragma once

#include <string>

class WrongAnimal
{
private:

protected:
	std::string type{};

	WrongAnimal(const std::string& type_);

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();

	virtual void makeSound() const;

	const std::string& getType() const;
	void setType(const std::string& type_);

	WrongAnimal& operator=(const WrongAnimal& other) = default;
};
