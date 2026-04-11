#include "phonebook.h"
#include <iostream>
#include <string>
#include <string_view>
#include <limits>

bool	clearFailedExtraction();
void	ignoreLine();
bool	hasUnextractedInput();
void	executeCommand(std::string_view sv, PhoneBook& pb);

int	main()
{
	PhoneBook		pb{};
	std::string		s{};

	while (1)
	{
		std::cout << "Enter a command [ADD, SEARCH, EXIT]" << "\n> ";
		std::cin >> s;
		if (clearFailedExtraction())
		{
			std::cout << "asd\n";
			continue;
		}
		executeCommand(s, pb);
	}
	return 0;
}

bool	clearFailedExtraction()
{
	if (!std::cin)
	{
		if (std::cin.eof())
			std::exit(0);
		std::cin.clear();
		ignoreLine();
		return true;
	}
	return false;
}

void	ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool	hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
}

void	executeCommand(std::string_view sv, PhoneBook& pb)
{
	if (sv == "ADD")
		pb.addContact();
	else if (sv == "SEARCH")
		pb.searchContact();
	else if (sv == "EXIT")
		std::exit(0);
}
