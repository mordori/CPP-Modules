#pragma once

#include <string>

class Animal
{
private:

protected:
	std::string type{};

	Animal();
	Animal(const Animal& other);
	Animal(const std::string& type_);

	Animal& operator=(const Animal& other) = default;

public:
	virtual ~Animal();

	virtual void makeSound() const = 0;

	const std::string& getType() const;
};
