#include <iostream>
#include <exception>
#include <cstddef>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	try
	{
		{
			Animal* animals[4];
			for (size_t i{}; i < 2; ++i)
				animals[i] = new Cat();
			for (size_t i{2}; i < 4; ++i)
				animals[i] = new Dog();
			for (auto a : animals)
				delete a;
		}
		std::cout << '\n';
		{
			Cat sleepyCat{};
			Cat grumpyCat{};
			sleepyCat.getBrain().addIdea("Sleep");
			grumpyCat.getBrain().addIdea("Violence");
			std::cout << "SleepyCat ideas: \n";
			sleepyCat.getBrain().listIdeas();
			std::cout << "GrumpyCat ideas: \n";
			grumpyCat.getBrain().listIdeas();
			Cat copyCat{grumpyCat};
			std::cout << "CopyCat ideas: \n";
			copyCat.getBrain().listIdeas();
			copyCat = sleepyCat;
			std::cout << "CopyCat ideas: \n";
			copyCat.getBrain().listIdeas();
		}
		std::cout << '\n';
		{
			Dog snoopDog{};
			snoopDog.getBrain().addIdea("Smoke weed every day");
			std::cout << "SnoopDog ideas: \n";
			snoopDog.getBrain().listIdeas();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
