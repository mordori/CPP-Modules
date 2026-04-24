#include <iostream>
#include <exception>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	try
	{
		{
			const Animal* animal = new Animal();
			const Animal* dog = new Dog();
			const Animal* cat = new Cat();
			std::cout << dog->getType() << '\n';
			std::cout << cat->getType() << '\n';
			animal->makeSound();
			cat->makeSound();
			dog->makeSound();
			delete animal;
			delete dog;
			delete cat;
		}
		std::cout << '\n';
		{
			Animal* animal = new Cat();
			Dog* dog = new Dog();
			Cat* cat = new Cat();
			std::cout << dog->getType() << '\n';
			std::cout << cat->getType() << '\n';
			delete animal;
			delete dog;
			delete cat;
		}
		std::cout << '\n';
		{
			Animal* animal = new Animal();
			Animal* catAnimal = new Cat();
			Cat* cat = new Cat();
			std::cout << animal->getType() << '\n';
			std::cout << catAnimal->getType() << '\n';
			std::cout << cat->getType() << '\n';
			animal->makeSound();
			catAnimal->makeSound();
			cat->makeSound();
			delete animal;
			delete catAnimal;
			delete cat;
		}
		std::cout << '\n';
		{
			const WrongAnimal* wrongAnimal = new WrongAnimal();
			const WrongCat* wrongCat = new WrongCat();
			const WrongAnimal* wrongCatAnimal = new WrongCat();
			std::cout << wrongCat->getType() << '\n';
			std::cout << wrongCatAnimal->getType() << '\n';
			wrongAnimal->makeSound();
			wrongCat->makeSound();
			wrongCatAnimal->makeSound();
			delete wrongAnimal;
			delete wrongCat;
			delete wrongCatAnimal;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
