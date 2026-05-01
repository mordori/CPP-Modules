#include "ScalarConverter.hpp"

#include <cctype>
#include <cstddef>
#include <string>
#include <string_view>
#include <charconv>
#include <type_traits>
#include <limits>
#include <iostream>
#include <cmath>
#include <sstream>

enum class LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

#pragma region Type Detection
static constexpr bool isChar(std::string_view sv)
{
	if (sv.length() == 1 && !std::isdigit(static_cast<unsigned char>(sv.front())))
		return true;
	return false;
}

static constexpr bool isInt(std::string_view sv)
{
	if (sv.front() == '-' || sv.front() == '+')
		sv.remove_prefix(1);
	for (char c : sv)
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return false;
	}
	return true;
}

static constexpr bool isDouble(std::string_view sv)
{
	if (sv == "nan")
		return true;
	if (sv.front() == '-' || sv.front() == '+')
		sv.remove_prefix(1);
	if (sv == "inf")
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

static constexpr bool isFloat(std::string_view sv)
{
	if (sv.back() != 'f')
		return false;
	sv.remove_suffix(1);
	return isDouble(sv);
}

static constexpr LiteralType detectType(std::string_view sv)
{
	if (sv.empty())
		return LiteralType::INVALID;
	if (isChar(sv))
		return LiteralType::CHAR;
	if (isInt(sv))
		return LiteralType::INT;
	if (isFloat(sv))
		return LiteralType::FLOAT;
	if (isDouble(sv))
		return LiteralType::DOUBLE;
	return LiteralType::INVALID;
}
#pragma endregion

#pragma region Type Conversion
template <typename T>
static constexpr bool isPseudoScalar(std::string_view sv, T& out)
{
	if constexpr (std::is_floating_point_v<T>)
	{
		if (sv == "nan" || sv == "nanf")
		{
			out = std::numeric_limits<T>::quiet_NaN();
			return true;
		}
		bool isNegative{ (sv.front() == '-') };
		if (isNegative || sv.front() == '+')
			sv.remove_prefix(1);
		if (sv == "inf" || sv == "inff")
		{
			out = std::numeric_limits<T>::infinity();
			out = isNegative ? -out : out;
			return true;
		}
	}
	return false;
}

template <typename T>
static constexpr bool convertScalar(std::string_view sv, T& out)
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
#pragma endregion

#pragma region Printing
static void printChar(double d, bool isPseudoScalar)
{
	if (isPseudoScalar || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << '\n';
		return;
	}
	char c = static_cast<char>(d);
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: " << c << '\n';
	else
		std::cout << "char: Non displayable" << '\n';
}

static void printInt(double d, bool isPseudoScalar)
{
	if (isPseudoScalar || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << '\n';
		return;
	}
	int i = static_cast<int>(d);
	std::cout << "int: " << i << '\n';
}

template <typename T>
static void printZeroDecimal(T value, bool isPseudoScalar)
{
	std::ostringstream oss;
	oss << value;
	std::string str = oss.str();
	if (str.find('.') == std::string::npos && str.find('e') == std::string::npos && !isPseudoScalar)
		std::cout << ".0";
}

static void printFloat(double d, bool isPseudoScalar)
{
	if (!isPseudoScalar && (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max()))
	{
		std::cout << "float: impossible" << '\n';
		return;
	}
	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	printZeroDecimal(f, isPseudoScalar);
	std::cout << "f\n";
}

static void printDouble(double d, bool isPseudoScalar)
{
	std::cout << "double: " << d;
	printZeroDecimal(d, isPseudoScalar);
	std::cout << '\n';
}

template <typename T>
static void printConversions(T value)
{
	double d = static_cast<double>(value);
	bool isPseudoScalar{};
	if constexpr (std::is_floating_point_v<T>)
		isPseudoScalar = (std::isnan(value) || std::isinf(value));
	printChar(d, isPseudoScalar);
	printInt(d, isPseudoScalar);
	printFloat(d, isPseudoScalar);
	printDouble(d, isPseudoScalar);
}
#pragma endregion

template <typename T>
static constexpr void buildConversions(std::string_view sv)
{
	T value{};
	if (convertScalar(sv, value))
		printConversions(value);
	else
		std::cerr << "Error: Invalid input.\n";
}

void ScalarConverter::convert(const std::string& str)
{
	std::string_view sv{ str };
	switch (detectType(sv))
	{
	case LiteralType::CHAR:
		printConversions(sv.front()); break;
	case LiteralType::INT:
		buildConversions<int>(sv); break;
	case LiteralType::FLOAT:
		buildConversions<float>(sv); break;
	case LiteralType::DOUBLE:
		buildConversions<double>(sv); break;
	case LiteralType::INVALID: [[fallthrough]];
	default:
		std::cerr << "Error: Invalid input.\n"; break;
	}
}
