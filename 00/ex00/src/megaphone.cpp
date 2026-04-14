#include <iostream>
#include <string_view>
#include <cctype>

char safeToUpper(char c);

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i{ 1 }; i < argc; ++i)
		for (char c : std::string_view{ argv[i] })
			std::cout << safeToUpper(c);
	std::cout << '\n';
	return 0;
}

char safeToUpper(char c)
{
	return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}
