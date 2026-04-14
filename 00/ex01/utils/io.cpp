#include "io.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <optional>
#include <charconv>
#include <cstddef>

void extractInputTo(std::string& str, std::optional<std::string_view> prompt)
{
	while (true)
	{
		if (prompt.has_value())
			std::cout << prompt.value();
		std::getline(std::cin, str);
		InputState state = validateExtractedInput();
		if (state == InputState::IO_CLOSURE)
			std::exit(0);
		else if (state == InputState::SUCCESS)
		{
			if (!trimString(str))
			{
				clearPreviousLine();
				continue;
			}
			return;
		}
		clearPreviousLine();
	}
}

std::optional<std::size_t> extractInput(std::optional<std::string_view> prompt)
{
	std::string str;
	while (true)
	{
		if (prompt.has_value())
			std::cout << prompt.value();
		std::getline(std::cin, str);
		InputState state = validateExtractedInput();
		if (state == InputState::IO_CLOSURE)
			std::exit(0);
		else if (state == InputState::SUCCESS)
		{
			if (!trimString(str))
			{
				clearPreviousLine();
				continue;
			}
			char* endptr{ str.data() + str.size() };
			std::size_t index{};
			auto[ptr, ec]{ std::from_chars(str.data(), endptr, index) };	// Structured binding, unpacks to separate variables
			if (ec != std::errc{} || ptr != endptr)
			{
				std::cout << '\n' << "Invalid input!" << "\n\n";
				return std::nullopt;
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
		std::cout << "Invalid input!" << "\n\n";
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
	std::cout << "\033[2J" << "\033[H";
}

void clearPreviousLine()
{
	std::cout << "\033[1A" << "\033[2K" << '\r';
}

bool trimString(std::string& str)
{
	std::size_t firstChar = str.find_first_not_of(" \t");
	if (firstChar == std::string::npos)
		return false;
	std::size_t lastChar = str.find_last_not_of(" \t");
	str.erase(lastChar + 1);
	str.erase(0, firstChar);
	return true;
}
