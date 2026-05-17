#include <exception>
#include <iostream>
#include <limits>
#include <list>
#include <random>
#include <ranges>
#include <vector>

#include "Span.hpp"

int main() {
	try {
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
		Span span{ 0 };
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		Span span{ 2 };
		span.addNumber(-1);
		span.addNumber(9);
		span.addNumber(6);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		Span span{ 3 };
		span.addNumber(0);
		span.addNumber(std::numeric_limits<int>::min());
		span.addNumber(std::numeric_limits<int>::max());
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
		std::cout << "Longest span: " << span.longestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution dist{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };

	try {
		Span span{ 10000 };
		auto view{ std::views::iota(0, 10000) | std::views::transform([&](int) { return dist(mt); }) };
		std::vector<int> vector_{ view.begin(), view.end() };
		span.addNumber(vector_);
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
		std::cout << "Longest span: " << span.longestSpan() << '\n';
		span.addNumber(1);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		Span span{ 10000 };
		auto view{ std::views::iota(0, 10000) | std::views::transform([&](int) { return dist(mt); }) };
		std::list<int> list_{ view.begin(), view.end() };
		span.addNumber(list_);
		std::cout << "Shortest span: " << span.shortestSpan() << '\n';
		std::cout << "Longest span: " << span.longestSpan() << '\n';
		span.addNumber(1);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	return 0;
}
