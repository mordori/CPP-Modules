#include "ScalarConverter.hpp"

#include <cctype>
#include <cstddef>
#include <string>
#include <string_view>
#include <charconv>
#include <type_traits>
#include <limits>

#include "Conversions.hpp"

enum class LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

constexpr bool isChar(std::string_view sv)
{
	if (sv.length() == 1 && !std::isdigit(static_cast<unsigned char>(sv[0])))
		return true;
	return false;
}

constexpr bool isInt(std::string_view sv)
{
	for (char c : sv)
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return false;
	}
	return true;
}

constexpr bool isDouble(std::string_view sv)
{
	if (sv == "nan" || sv == "inf")
		return true;
	std::size_t dots{};
	std::size_t digits{};
	for (char c : sv)
	{
		if (c == '.')
			++dots;
		else if (std::isdigit(static_cast<unsigned char>(c)))
			++digits;
		else
			return false;
	}
	return (dots == 1 && digits > 0);
}

constexpr bool isFloat(std::string_view sv)
{
	if (sv.back() != 'f')
		return false;
	sv.remove_suffix(1);
	return isDouble(sv);
}

constexpr LiteralType detectType(std::string_view sv)
{
	if (sv.empty())
		return LiteralType::INVALID;
	if (isChar(sv))
		return LiteralType::CHAR;
	if (sv[0] == '-' || sv[0] == '+')
		sv.remove_prefix(1);
	if (isInt(sv))
		return LiteralType::INT;
	if (isDouble(sv))
		return LiteralType::DOUBLE;
	if (isFloat(sv))
		return LiteralType::FLOAT;
	return LiteralType::INVALID;
}

template <typename T>
constexpr bool isPseudoScalar(std::string_view sv, T& out)
{
	if constexpr (std::is_floating_point_v<T>)
	{
		bool isNegative{};
		if (sv.front() == '-')
		{
			isNegative = true;
			sv.remove_prefix(1);
		}
		else if (sv.front() == '+')
			sv.remove_prefix(1);
		if (sv == "nan" || sv == "nanf")
		{
			out = std::numeric_limits<T>::quiet_NaN();
			return true;
		}
		if (sv == "inf" || sv == "inff")
		{
			out = isNegative ? -std::numeric_limits<T>::infinity() : std::numeric_limits<T>::infinity();
			return true;
		}
	}
	return false;
}

template <typename T>
constexpr bool convertScalar(std::string_view sv, T& out)
{
	if (isPseudoScalar(sv, out))
		return true;
	if (sv.front() == '+')
		sv.remove_prefix(1);
	const char* end{ sv.data() + sv.size() };
	auto res = std::from_chars(sv.data(), end, out);
	if (res.ec != std::errc{})
		return false;
	if (res.ptr != end)
	{
		if constexpr (std::is_same_v<T, float>)
		{
			if (*res.ptr == 'f' && (res.ptr + 1) == end)
				return true;
		}
		return false;
	}
	return true;
}

template <typename T>
constexpr void buildConversions(std::string_view sv)
{
	T value{};
	if (convertScalar(sv, value))
		Conversions{ value };
}

void ScalarConverter::convert(const std::string& str)
{
	std::string_view sv{ str };
	switch (detectType(sv))
	{
	case LiteralType::CHAR:
		Conversions{ sv[0] }; break;
	case LiteralType::INT:
		buildConversions<int>(sv); break;
	case LiteralType::DOUBLE:
		buildConversions<double>(sv); break;
	case LiteralType::FLOAT:
		buildConversions<float>(sv); break;
	case LiteralType::INVALID:
	default:
		break;
	}
}
