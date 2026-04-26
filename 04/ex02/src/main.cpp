#include <iostream>
#include <exception>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* animalCat = new Cat();
	Animal* animalDog = new Dog();
	animalCat->makeSound();
	animalDog->makeSound();

	std::cout << '\n';

	Cat* cat = new Cat();
	Dog* dog = new Dog();
	cat->makeSound();
	dog->makeSound();

	std::cout << '\n';

	// Not possible to instantiate
	// Animal* animal = new Animal();
	// Animal animal{};
	// Animal animal{ animalCat };

	// *cat = *dog;
	// *animalCat = *cat;

	Cat copyCat{};
	copyCat = *cat;

	std::cout << '\n';

	delete animalCat;
	delete animalDog;
	delete cat;
	delete dog;

	return 0;
}
