#pragma once

#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:
public:
	WrongCat();
	WrongCat(const WrongCat& other);
	~WrongCat() override;

	void makeSound() const;

	WrongCat& operator=(const WrongCat& other) = default;
};
