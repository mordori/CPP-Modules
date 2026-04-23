#pragma once

#include <string>

class Animal
{
private:

protected:
	std::string type{};

	Animal(const std::string& type_);

public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();

	virtual void makeSound() const;

	const std::string& getType() const;

	Animal& operator=(const Animal& other) = default;
};
