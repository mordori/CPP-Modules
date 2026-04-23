#include "Brain.hpp"

#include <cstddef>
#include <iostream>
#include <string_view>

Brain::Brain()
{ std::cout << "\033[1;34mBrain::Constructor\033[0m\n"; }

Brain::Brain(const Brain& other)
{
	std::cout << "\033[1;34mBrain::Copy Constructor\033[0m\n";
	for (size_t i{}; i < MAX_IDEAS; ++i)
	{
		if (other.ideas[i].empty())
			break;
		ideas[i] = other.ideas[i];
	}
}

Brain::~Brain()
{ std::cout << "\033[1;31mBrain::Destructor\033[0m\n"; }

void Brain::addIdea(const std::string& idea) {
  ideas[index] = idea;
  index = (index + 1) % MAX_IDEAS;
}

void Brain::listIdeas()
{
	for (std::string_view s : ideas)
	{
		if (s.empty())
			break;
		std::cout << s << '\n';
	}
}
