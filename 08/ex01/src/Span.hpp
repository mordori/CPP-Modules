#pragma once

#include <concepts>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <stdexcept>
#include <vector>

class Span {
private:
	unsigned int _capacity{};
	mutable std::vector<int> _data;
	mutable bool _isSorted{};

public:
	Span() = delete;
	explicit Span(unsigned int N);
	Span(const Span& other) = default;
	~Span() = default;

	Span& operator=(const Span& other) = default;

	template <std::ranges::range T>
		requires std::same_as<std::ranges::range_value_t<T>, int>
	void addNumber(const T& container) {
		auto size = std::ranges::distance(container);
		if (static_cast<std::size_t>(size) > static_cast<std::size_t>(_capacity) - _data.size())
			throw std::length_error{ "Span is at maximum capacity!" };
		_data.insert(_data.end(), std::ranges::begin(container), std::ranges::end(container));
		_isSorted = false;
	}
	void addNumber(int number);
	[[nodiscard]] unsigned int shortestSpan() const;
	[[nodiscard]] unsigned int longestSpan() const;
};
