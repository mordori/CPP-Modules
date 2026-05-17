#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**) {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror;  //

	Array<const float> a{};
	try {
		std::cout << a.size() << "\n";
		std::cout << a[0] << "\n";
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	Array<int> b{ 3 };
	try {
		std::cout << b.size() << "\n";
		b[0] = 1;
		std::cout << b[0] << "\n";
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
