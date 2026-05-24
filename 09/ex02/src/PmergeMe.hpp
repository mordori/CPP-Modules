#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <concepts>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <ratio>
#include <span>
#include <vector>

template <typename T>
concept UIntRange = std::ranges::range<T> && std::same_as<std::ranges::range_value_t<T>, unsigned int>;

class PmergeMe {
private:
	std::vector<unsigned int> _data;

public:
	PmergeMe(const std::span<const char*>& args);
	~PmergeMe() = default;
	PmergeMe() = delete;
	PmergeMe(const PmergeMe& other) = delete;
	PmergeMe& operator=(const PmergeMe& other) = delete;

	[[nodiscard]] const std::vector<unsigned int>& getUnsortedSequence() const;

	double run(UIntRange auto& r) {
		auto startTime{ std::chrono::steady_clock::now() };
		r.assign(_data.cbegin(), _data.cend());
		sort(r, 1);
		auto endTime{ std::chrono::steady_clock::now() };
		std::chrono::duration<double, std::micro> sortTime{ endTime - startTime };
		assert(std::ranges::is_sorted(r) && "container is not sorted");
		return sortTime.count();
	}

	void sort(UIntRange auto& r, std::size_t chunk) {
		auto chunk2 = chunk * 2;
		if (chunk2 > r.size())
			return;
		auto it{ std::ranges::begin(r) };
		std::size_t remaining{ r.size() };
		while (remaining >= chunk2) {
			auto next{ std::next(it, static_cast<long>(chunk)) };
			auto a{ std::next(it, static_cast<long>(chunk - 1)) };
			auto b{ std::next(next, static_cast<long>(chunk - 1)) };
			if (*a > *b)
				std::swap_ranges(it, next, next);
			std::advance(it, chunk2);
			remaining -= chunk2;
		}
		sort(r, chunk2);
		index(r, chunk);
	}

	void index(UIntRange auto& r, std::size_t chunk) {
		auto chunk2 = chunk * 2;
		using It = decltype(std::ranges::begin(r));
		std::vector<It> main;
		std::vector<It> pend;
		auto it{ std::ranges::begin(r) };
		std::size_t remaining{ r.size() };
		if (remaining >= chunk2) {
			auto b{ it };
			auto a{ std::next(it, static_cast<long>(chunk)) };
			main.push_back(b);
			main.push_back(a);
			std::advance(it, chunk2);
			remaining -= chunk2;
		}
		while (remaining >= chunk2) {
			auto b{ it };
			auto a{ std::next(it, static_cast<long>(chunk)) };
			main.push_back(a);
			pend.push_back(b);
			std::advance(it, chunk2);
			remaining -= chunk2;
		}
		if (remaining >= chunk)
			pend.push_back(it);
	}
};
