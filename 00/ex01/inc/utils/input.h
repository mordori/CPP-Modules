#pragma once

#include <string>
#include <string_view>
#include <optional>

enum class InputState
{
	SUCCESS,
	INVALID,
	IO_CLOSURE
};

InputState validateExtractedInput();
void extractInputTo(std::string& str, std::optional<std::string_view> prompt);
long extractInput(std::optional<std::string_view> prompt);
void ignoreUnextractedInput();
bool hasUnextractedInput();
void clearTerminal();
