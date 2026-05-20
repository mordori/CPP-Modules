#include "BitcoinExchange.hpp"

#include <charconv>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>

namespace {
bool isValidDate(std::string_view sv) {
	if (sv.size() != 10 || sv[4] != '-' || sv[7] != '-')
		return false;
	int year{}, month{}, day{};
	auto [p1, e1]{ std::from_chars(sv.data(), sv.data() + 4, year) };
	auto [p2, e2]{ std::from_chars(sv.data() + 5, sv.data() + 7, month) };
	auto [p3, e3]{ std::from_chars(sv.data() + 8, sv.data() + 10, day) };
	if (e1 != std::errc{} || e2 != std::errc{} || e3 != std::errc{})
		return false;
	std::chrono::year_month_day date{ //
		std::chrono::year{ year },
		std::chrono::month{ static_cast<unsigned>(month) },
		std::chrono::day{ static_cast<unsigned>(day) }
	};
	return date.ok();
}

std::optional<float> convertFloat(std::string_view sv) {
	if (sv.empty())
		return std::nullopt;
	if (sv.front() == '+')
		sv.remove_prefix(1);
	float value{};
	auto [ptr, ec]{ std::from_chars(sv.data(), sv.data() + sv.size(), value) };
	if (ec != std::errc{} || ptr != sv.data() + sv.size())
		return std::nullopt;
	return value;
}

std::string_view trimWs(std::string_view sv) {
	std::size_t firstChar = sv.find_first_not_of(" \t");
	if (firstChar == std::string::npos)
		return {};
	std::size_t lastChar = sv.find_last_not_of(" \t");
	return sv.substr(firstChar, lastChar - firstChar + 1);
}

std::optional<std::pair<std::string_view, std::string_view>> parseViews(const std::string& line, char delimiter) {
	std::size_t delimiterPos{ line.find(delimiter) };
	if (delimiterPos == std::string::npos)
		return std::nullopt;
	std::string_view lineView{ line };
	std::string_view dateView{ trimWs(lineView.substr(0, delimiterPos)) };
	std::string_view valueView{ trimWs(lineView.substr(delimiterPos + 1)) };
	return std::pair{ dateView, valueView };
}

std::optional<std::pair<std::string_view, float>> parseLine(const std::string& line, char delimiter) {
	auto views{ parseViews(line, delimiter) };
	if (!views.has_value())
		return std::nullopt;
	auto value{ convertFloat(views->second) };
	if (!value.has_value())
		return std::nullopt;
	return std::pair{ views->first, *value };
}

bool isValidHeader(const std::string& line, char delimiter, std::string_view value) {
	auto views{ parseViews(line, delimiter) };
	if (!views.has_value())
		return false;
	return (views->first == "date" && views->second == value);
}

template <typename F>
void parseFile(const std::string& inFile, char delimiter, std::string_view headerValue, F func) {
	std::ifstream file{ inFile };
	if (!file.is_open())
		throw std::runtime_error{ "Error: could not open file '" + inFile + "'" };
	std::string line;
	std::getline(file, line);
	if (!isValidHeader(line, delimiter, headerValue))
		std::cerr << "Error: bad header in '" << inFile << '\n';
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		auto data{ parseLine(line, delimiter) };
		func(data, line);
	}
}
}

void BitcoinExchange::loadDatabase(const std::string& db) {
	auto insertData = [this](const auto& data, const std::string& line) {
		if (!data.has_value() || !isValidDate(data->first) || data->second < 0.0f)
			throw std::runtime_error{ "Error: bad format => " + line };
		_database[std::string{ data->first }] = data->second;
	};
	parseFile(db, ',', "exchange_rate", insertData);
}

void BitcoinExchange::processInput(const std::string& input) const {
	auto processData = [this](const auto& data, const std::string& line) {
		if (!data.has_value()) {
			std::cerr << "Error: bad format => " << line << '\n';
			return;
		}
		if (data->second < 0.0f) {
			std::cerr << "Error: not a positive number.\n";
			return;
		}
		if (data->second > 1000.0f) {
			std::cerr << "Error: too large number.\n";
			return;
		}
		if (!isValidDate(data->first)) {
			std::cerr << "Error: invalid date => " << data->first << "\n";
			return;
		}
		auto it = _database.lower_bound(data->first);
		if (it == _database.end() || it->first != data->first) {
			if (it == _database.begin()) {
				std::cerr << "Error: data is older than database.\n";
				return;
			}
			--it;
		}
		std::cout << data->first << " => " << data->second << " = " << data->second * it->second << '\n';
	};
	parseFile(input, '|', "value", processData);
}
