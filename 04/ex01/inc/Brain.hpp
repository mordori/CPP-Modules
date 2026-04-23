#pragma once

#include <string>
#include <cstddef>

class Brain
{
private:
	static constexpr std::size_t MAX_IDEAS{ 100 };
	std::size_t index{};
	std::string ideas[MAX_IDEAS]{};

public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	void addIdea(const std::string& idea);
	void listIdeas();

	Brain& operator=(const Brain& other) = default;
};
