#include "PhoneBook.hpp"
#include "io.hpp"

#include <iostream>
#include <string>
#include <string_view>

void executeCommand(std::string_view cmd, PhoneBook& pb);

int main()
{
	PhoneBook pb{};
	std::string cmd{};

	clearTerminal();
	std::cout << '\n' << "PHONEBOOK" << "\n\n";
	while (true)
	{
		std::cout << "--- Enter a command ---" << '\n';
		std::cout << "[ADD, SEARCH, EXIT]" << "\n\n";
		extractInputTo(cmd, "> ");
		InputState state = validateExtractedInput();
		if (state == InputState::IO_CLOSURE)
			std::exit(0);
		else if (state == InputState::SUCCESS)
		{
			clearTerminal();
			std::cout << '\n';
			executeCommand(cmd, pb);
		}
	}
	return 0;
}

void executeCommand(std::string_view cmd, PhoneBook& pb)
{
	if (cmd == "ADD")
		pb.addContact();
	else if (cmd == "SEARCH")
		pb.searchContact();
	else if (cmd == "EXIT")
		std::exit(0);
	else
		std::cout << "Invalid command!" << "\n\n";
}
