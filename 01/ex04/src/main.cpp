#include <cstddef>
#include <iostream>
#include <string>

#include "files.hpp"
#include "strings.hpp"

bool run(int argc, char **argv);

int main(int argc, char **argv)
{
	try
	{
		if (!run(argc, argv))
			return 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	catch(...)
	{
		std::cerr << "Unknown throw occurred" << '\n';
		return 1;
	}
	return 0;
}

bool run(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Usage: ./replace <fileName> <s1> <s2>" << '\n';
		return false;
	}
	const std::string fileName{ argv[1] };
	const std::string s1{ argv[2] };
	const std::string s2{ argv[3] };
	if (CHECK_EMPTY_STR(fileName) || CHECK_EMPTY_STR(s1))
		return false;
	std::string src{};
	if (!readFileToString(src, fileName))
		return false;
	replace(src, s1, s2);
	if (!writeStringToFile(src, fileName + ".replace"))
		return false;
	return true;
}
