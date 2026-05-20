#include <exception>
#include <iostream>
#include <limits>
#include <list>
#include <random>
// #include <ranges>
#include <vector>

#include "Span.hpp"

int main() {
	try {
		std::cout << "TEST: normal\n";
		Span span{ 3 };
		span.addNumber(1);
		span.addNumber(-1);
		span.addNumber(9);
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
		std::cout << "Longest span: " << span.longestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		std::cout << "TEST: Not enough elements\n";
		Span span{ 2 };
		span.addNumber(1);
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		std::cout << "TEST: construction error\n";
		Span span{ 0 };
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		std::cout << "TEST: over maximum capacity\n";
		Span span{ 2 };
		span.addNumber(-1);
		span.addNumber(9);
		span.addNumber(6);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		std::cout << "TEST: longest possible span [INT_MIN, INT_MAX] (UINT_MAX "
				  << std::numeric_limits<unsigned int>::max() << ")\n";
		Span span{ 3 };
		span.addNumber(std::numeric_limits<int>::min());
		span.addNumber(std::numeric_limits<int>::max());
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
		std::cout << "Longest span: " << span.longestSpan() << '\n';
		span.addNumber(0);
		std::cout << "Added 0 to the container.\n";
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution dist{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };

	try {
		std::cout << "TEST: add vector to span\n";
		Span span{ 10000 };
		// std=c++23
		// auto view{ std::views::iota(0, 10000) | std::views::transform([&](int) { return dist(mt); }) };
		// std::vector<int> vector_{ view.begin(), view.end() };
		std::vector<int> vector_(10000);
		for (auto& i : vector_)
			i = dist(mt);
		span.insertContainer(vector_);
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
		std::cout << "Longest span: " << span.longestSpan() << '\n';
		span.addNumber(1);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		std::cout << "TEST: add list to span\n";
		Span span{ 10000 };
		std::list<int> list_(10000);
		for (auto& i : list_)
			i = dist(mt);
		span.insertContainer(list_);
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
		std::cout << "Longest span: " << span.longestSpan() << '\n';
		span.addNumber(1);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	return 0;
}
