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
			std::cout << dog->getType() << " " << std::endl;
			std::cout << cat->getType() << " " << std::endl;
			cat->makeSound();
			dog->makeSound();
			animal->makeSound();
			delete animal;
			delete dog;
			delete cat;
		}
		std::cout << std::endl;
		{
			Animal* animal = new Cat();
			Dog* dog = new Dog();
			Cat* cat = new Cat();
			std::cout << dog->getType() << " " << std::endl;
			std::cout << cat->getType() << " " << std::endl;
			delete animal;
			delete dog;
			delete cat;
		}
		std::cout << std::endl;
		{
			Animal* animal = new Animal();
			Animal* catAnimal = new Cat();
			Cat* cat = new Cat();
			std::cout << animal->getType() << " " << std::endl;
			std::cout << catAnimal->getType() << " " << std::endl;
			std::cout << cat->getType() << " " << std::endl;
			animal->makeSound();
			catAnimal->makeSound();
			cat->makeSound();
			delete animal;
			delete catAnimal;
			delete cat;
		}
		{
			const WrongAnimal* wrongAnimal = new WrongAnimal();
			const WrongCat* wrongCat = new WrongCat();
			const WrongAnimal* wrongCatAnimal = new WrongCat();
			std::cout << wrongCat->getType() << " " << std::endl;
			std::cout << wrongCatAnimal->getType() << " " << std::endl;
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
