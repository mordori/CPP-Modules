#include "files.hpp"

#include <cstddef>
#include <ios>
#include <iostream>
#include <string>
#include <fstream>

bool readFileToString(std::string& src, const std::string& fileName)
{
	std::ifstream inFile{ fileName, std::ios::binary | std::ios::ate };
	if (!inFile.is_open())
	{
		std::cerr << "Error: Could not open file <" << fileName << ">" << '\n';
		return false;
	}
	std::streamsize size = static_cast<std::streamsize>(inFile.tellg());
	src.resize(static_cast<std::size_t>(size));
	inFile.seekg(0, std::ios::beg);
	if (!inFile.read(src.data(), size))
	{
		std::cerr << "Error: Could not read file <" << fileName << ">" << '\n';
		return false;
	}
	return true;
}

bool writeStringToFile(const std::string& src, const std::string& fileName)
{
	std::ofstream outFile{ fileName };
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not write to file <" << fileName << ">" << '\n';
		return false;
	}
	outFile << src;
	return true;
}
