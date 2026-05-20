#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: input sequence is require as argument.\n";
		return 1;
	}
	try {
		RPN rpn{};
		rpn.calculate(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
