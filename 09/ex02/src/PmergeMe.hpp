#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <iostream>
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
		if (chunk2 > std::ranges::size(r))
			return;
		auto it{ std::ranges::begin(r) };
		std::size_t remaining{ std::ranges::size(r) };
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
		using It = decltype(std::ranges::begin(r));
		std::vector<It> main;
		std::vector<It> pend;
		index(r, main, pend, chunk);
		jacobsthal(r, main, pend, chunk);
		reassemble(r, main, chunk);
	}

	void index(UIntRange auto& r, auto& main, auto& pend, std::size_t chunk) {
		auto chunk2 = chunk * 2;
		auto it{ std::ranges::begin(r) };
		std::size_t remaining{ std::ranges::size(r) };
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

	void jacobsthal(UIntRange auto& r, auto& main, auto& pend, std::size_t chunk) {
		using It = decltype(std::ranges::begin(r));
		if (pend.empty())
			return;
		std::size_t prev_jacob{ 1 };
		std::size_t curr_jacob{ 3 };
		std::size_t added{};
		while (true) {
			std::size_t start{ curr_jacob - 2 };
			if (start >= pend.size())
				start = pend.size() - 1;
			std::size_t end{ prev_jacob - 1 };
			for (std::size_t i{ start };; --i) {
				auto it_loser{ pend[i] };
				auto comp{ [chunk](It lhs, It rhs) {
					auto val_lhs{ std::next(lhs, static_cast<long>(chunk - 1)) };
					auto val_rhs{ std::next(rhs, static_cast<long>(chunk - 1)) };
					return *val_lhs < *val_rhs;
				} };
				std::size_t bound = i + 2 + added;
				if (bound > main.size())
					bound = main.size();
				auto search_end{ main.begin() + static_cast<long>(bound) };
				auto insertPos{ std::upper_bound(main.begin(), search_end, it_loser, comp) };
				main.insert(insertPos, it_loser);
				++added;
				if (i == end) {
					break;
				}
			}
			if (start == pend.size() - 1)
				break;
			std::size_t next_jacob{ curr_jacob + (2 * prev_jacob) };
			prev_jacob = curr_jacob;
			curr_jacob = next_jacob;
		}
	}

	void reassemble(UIntRange auto& r, auto& main, std::size_t chunk) {
		using It = decltype(std::ranges::begin(r));
		std::vector<unsigned int> temp;
		temp.reserve(std::ranges::size(r));
		for (It it_main : main) {
			auto chunk_end{ std::next(it_main, static_cast<long>(chunk)) };
			for (auto val_it{ it_main }; val_it != chunk_end; ++val_it)
				temp.push_back(*val_it);
		}

		std::size_t remainder{ std::ranges::size(r) % chunk };
		if (remainder > 0) {
			auto tail{ std::ranges::end(r) };
			std::advance(tail, -static_cast<long>(remainder));
			for (auto val_it{ tail }; val_it != std::ranges::end(r); ++val_it)
				temp.push_back(*val_it);
		}

		std::copy(temp.begin(), temp.end(), std::ranges::begin(r));
	}
};
