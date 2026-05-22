#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: expression is required as a single argument\n";
		return 1;
	}
	try {
		RPN rpn{};
		std::cout << rpn.evaluate(argv[1]) << '\n';
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}
