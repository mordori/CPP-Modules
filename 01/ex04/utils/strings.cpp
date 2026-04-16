#include "strings.hpp"

#include <string>
#include <iostream>

bool checkEmptyString(const std::string& str, const std::string& name, const std::string& file, int line)
{
	if (str.empty())
	{
		std::cerr << "Error: <"<< name << "> cannot be an empty string" << '\n';
		std::cerr << file << ", line: " << line << '\n';
		return true;
	}
	return false;
}

void replace(std::string& src, const std::string& s1, const std::string& s2)
{
	size_t pos{};
	while ((pos = src.find(s1, pos)) != std::string::npos)
	{
		src.erase(pos, s1.length());
		src.insert(pos, s2);
		pos += s2.length();
	}
}
