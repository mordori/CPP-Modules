#pragma once

#include <functional>
#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, float, std::less<>> _database;

public:
	BitcoinExchange() = default;
	~BitcoinExchange() = default;

	BitcoinExchange(const BitcoinExchange& other) = delete;
	BitcoinExchange& operator=(const BitcoinExchange& other) = delete;

	void loadDatabase(const std::string& db);
	void processInput(const std::string& input) const;
};
