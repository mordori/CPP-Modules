#include "Span.hpp"

#include <algorithm>
#include <limits>
// #include <ranges>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) {
	if (N < 2)
		throw std::logic_error{ "Minimum capacity for span is 2!" };
	_capacity = N;
}

void Span::addNumber(int number) {
	if (_data.size() >= _capacity)
		throw std::length_error{ "Span is at maximum capacity!" };
	_data.push_back(number);
	_isSorted = false;
}

unsigned int Span::longestSpan() const {
	auto [min, max]{ std::ranges::minmax(_data) };
	return static_cast<unsigned int>(max) - static_cast<unsigned int>(min);
}

unsigned int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw std::logic_error{ "Not enough elements to find a span!" };
	if (!_isSorted) {
		std::ranges::sort(_data);
		_isSorted = true;
	}
	auto it{ _data.begin() };
	auto next{ it + 1 };
	unsigned int shortest{ std::numeric_limits<unsigned int>::max() };
	while (next != _data.end()) {
		shortest = std::min(shortest, static_cast<unsigned int>(*next) - static_cast<unsigned int>(*it));
		++it;
		++next;
	}
	return shortest;

	// std=c++23
	// auto view = _data | std::views::adjacent_transform<2>([](int a, int b) {
	// 	return static_cast<unsigned int>(b) - static_cast<unsigned int>(a);
	// });
	// return std::ranges::min(view);
}
