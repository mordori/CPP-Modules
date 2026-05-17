#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
void printT(const T& t) {
	std::cout << t << '\n';
}

void increment(int& i) {
	++i;
}

int main() {
	int ints[3] = { 0, 1, 2 };
	iter(ints, 3, increment);
	iter(ints, 3, printT<int>);
	std::cout << '\n';

	const int constInts[3] = { 9, 10, 11 };
	iter(constInts, 3, printT<const int>);
	std::cout << '\n';

	std::string strings[3] = { "A", "B", "C" };
	iter(strings, 3, printT<std::string&>);
	std::cout << '\n';

	const std::string constStrings[3] = { "X", "Y", "Z" };
	iter(constStrings, 3, printT<const std::string&>);
	return 0;
}
