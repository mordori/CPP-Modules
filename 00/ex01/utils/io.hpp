#pragma once

#include <string>
#include <string_view>
#include <optional>
#include <cstddef>
#include <ios>

enum class InputState
{
	SUCCESS,
	INVALID,
	IO_CLOSURE
};

struct IosFlags
{
	std::ios_base& m_stream;
	std::ios_base::fmtflags m_origFlags;

	explicit IosFlags(std::ios_base& stream);
	~IosFlags();
};

InputState validateExtractedInput();
void extractInputTo(std::string& str, std::optional<std::string_view> prompt = std::nullopt);
std::optional<std::size_t> extractInput(std::optional<std::string_view> prompt);
void ignoreUnextractedInput();
bool hasUnextractedInput();
void clearTerminal();
void clearPreviousLine();
bool trimString(std::string& str);
