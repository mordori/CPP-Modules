#include "input.h"

#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <optional>

void extractInputTo(std::string& str, std::optional<std::string_view> prompt)
{
	while (true)
	{
		if (prompt)
			std::cout << *prompt;
		std::getline(std::cin >> std::ws, str);
		InputState state = validateExtractedInput();
		if (state == InputState::IO_CLOSURE)
			std::exit(0);
		else if (state == InputState::SUCCESS)
			return;
	}
}

long extractInput(std::optional<std::string_view> prompt)
{
	long index{};
	while (true)
	{
		if (prompt)
			std::cout << *prompt;
		std::cin >> index;
		InputState state = validateExtractedInput();
		if (state == InputState::IO_CLOSURE)
			std::exit(0);
		else if (state == InputState::SUCCESS)
		{
			if (hasUnextractedInput())
			{
				std::cout << "Invalid input" << "\n\n";
				ignoreUnextractedInput();
				continue;
			}
			return index;
		}
	}
}

InputState validateExtractedInput()
{
	if (!std::cin)
	{
		if (std::cin.eof())
			return InputState::IO_CLOSURE;
		std::cin.clear();
		ignoreUnextractedInput();
		std::cout << "Invalid input" << "\n\n";
		return InputState::INVALID;
	}
	return InputState::SUCCESS;
}

void ignoreUnextractedInput()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
}

void clearTerminal()
{
	std::cout << "\033[2J\033[H";
}
