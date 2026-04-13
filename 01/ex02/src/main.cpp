#include <string>
#include <iostream>

int main()
{
	const std::string str{ "HI THIS IS BRAIN" };
	const std::string* stringPTR{ &str };
	const std::string& stringREF{ str };
	std::cout << &str << '\n';
	std::cout << &stringPTR << '\n';
	std::cout << &stringREF << '\n';
	std::cout << str << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';
	return 0;
}
